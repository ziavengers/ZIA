#include "parsing_http/ParserHttp.hh"

ParserHttp::ParserHttp(IProducterStream& stream) : ConsumerParser(stream)
{}
#include <iostream>
bool ParserHttp::readHttp(std::string& method, std::string& url, std::map< std::string, std::string >& header, std::string& content)
{
  beginCapture("method");
  if (readTextIgnoreCase("OPTIONS") || readTextIgnoreCase("GET") || readTextIgnoreCase("HEAD") || readTextIgnoreCase("POST") || readTextIgnoreCase("PUT") || readTextIgnoreCase("DELETE") || readTextIgnoreCase("TRACE") || readTextIgnoreCase("CONNECT"))
    {
      endCapture("method", method);
      readLWS();
      bool cont = false;
      beginCapture("url");
      while (readChar('/') || readChar('.') || readChar('?') || readChar('%') || readChar('&')
	     || readChar('=') || readChar('+') || readChar(':') || readChar('-')
	     || readRange('a', 'z') || readRange('A', 'Z') || readRange('0', '9'))
	cont = true;
      endCapture("url", url);
      readLWS();
      if (cont && readTextIgnoreCase("HTTP/1.1") && readCRLF())
	{
	  cont = true;
	  while (!(readCRLF() || readEOF()) && cont)
	    {
	      cont = false;
	      if (beginCapture("name"))
		{
		  std::string name, value;
		  bool cont2 = false;
		  while (readChar('-') || readRange('a', 'z') || readRange('A', 'Z'))
		    cont2 = true;
		  if (cont2 && endCapture("name", name) && (readLWS() || true) && readChar(':') && (readLWS() || true))
		    {
		      // Trouver comment faire un readUntil() sur plusieurs textes possibles
		      if (beginCapture("value") && readUntil("\r\n") && endCapture("value", value))
			{
			  header[name] = value;
			  cont = true;
			}
		    }
		}
	    }
	  if (cont
	      && beginCapture("content")
	      && readUntilEOF()
	      && endCapture("content", content))
	    return true;
	}
    }
  method.clear();
  url.clear();
  header.clear();
  content.clear();
  return false;
}

bool ParserHttp::readCRLF()
{
  // return readText("\r\n");
  return (readText("\r\n") || readChar('\r') || readChar('\n'));
}

bool ParserHttp::readLWS()
{
  saveContext();
  readCRLF();
  if (!(readChar(' ') || readChar('\t')))
    {
      restoreContext();
      return false;
    }
  validContext();
  while (readChar(' ') || readChar('\t'))
    ;
  return true;
}
