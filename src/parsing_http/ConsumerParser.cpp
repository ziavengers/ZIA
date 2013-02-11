#include "parsing_http/ConsumerParser.hpp"

bool ConsumerParser::readBlock()
{
  try
    {
      std::string s(_prod.nextString());
      _buff += s;
      if (_cache.size())
      	_cache.top() += s;
      return true;
    }
  catch (...)
    {
      return false;
    }
}

bool ConsumerParser::readBlockIfEmpty(size_t len)
{
  bool ret = true;
  while (_buff.size() < len && (ret = readBlock()))
    ;
  return ret;
}

bool ConsumerParser::readText(const std::string& s)
{
  readBlockIfEmpty(s.size());
  if (_buff.find(s) == 0)
    {
      appendText(s);
      return true;
    }
  return false;
}

bool ConsumerParser::readEOF()
{
  return !readBlockIfEmpty();
}

bool ConsumerParser::readUntil(char c)
{
  bool ret;
  std::string save;

  ret = false;
  while (readBlockIfEmpty() && !ret)
    {
      ret = peekChar(c);
      save += _buff[0];
      _buff = _buff.substr(1);
    }
  if (ret)
    appendText(save, false);
  else
    _buff = save + _buff;
  return ret;
}

bool ConsumerParser::readUntilEOF()
{
  std::string save;

  while (!readEOF())
    {
      save += _buff[0];
      _buff = _buff.substr(1);
    }
  appendText(save, false);
  return true;
}

bool ConsumerParser::readInteger()
{
  if (!readRange('0', '9'))
    return false;
  while (readRange('0', '9'))
    ;
  return true;
}

bool ConsumerParser::readIdentifier()
{
  if (!(readRange('a', 'z') || readRange('A', 'Z') || readChar('_')))
    return false;
  while (readRange('0', '9') || readRange('a', 'z') || readRange('A', 'Z') || readChar('_'))
    ;
  return true;
}

bool ConsumerParser::saveContext()
{
  _cache.push(_buff);
  return true;
}

bool ConsumerParser::restoreContext()
{
  if (!_cache.size())
    return false;
  _buff = _cache.top();
  _cache.pop();
  return true;
}

bool ConsumerParser::validContext()
{
  if (!_cache.size())
    return false;
  std::string save = _cache.top();
  _cache.pop();
  if (_cache.size())
    _cache.top() += save;
  return true;
}
