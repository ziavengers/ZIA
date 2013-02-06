#include "ParserHttp.hh"

ParserHttp::ParserHttp(IProducterStream& stream) : ConsumerParser(stream)
{}

bool ParserHttp::readHttp(std::map<std::string, std::string>& header)
{
  if ((readText("GET") || readText("POST")) && readChar(' '))
    {
      bool cont = false;
      while (readChar('/') || readChar('.') || readChar('?') || readChar('%') || readChar('&')
	     || readChar('=') || readChar('+') || readChar(':') || readChar('-')
	     || readRange('a', 'z') || readRange('A', 'Z') || readRange('0', '9'))
	cont = true;
      if (cont && readText(" http/1.0") && readChar('\n'))
	{
	  cont = true;
	  while (!(readChar('\n') || readEOF()) && cont)
	    {
	      cont = false;
	      if (beginCapture("name"))
		{
		  std::string name, value;
		  bool cont2 = false;
		  while (readChar('-') || readRange('a', 'z') || readRange('A', 'Z'))
		    cont2 = true;
		  if (cont2 && endCapture("name", name) && readChar(':'))
		    {
		      if (beginCapture("value") && readUntil('\n') && endCapture("value", value))
			{
			  header[name] = value;
			  cont = true;
			}
		    }
		}
	    }
	  if (cont && readUntilEOF())
	    return true;
	}
    }
  header.clear();
  return false;
}
