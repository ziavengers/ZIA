#include "parsing_http/ParserHttp.hh"

ParserHttp::ParserHttp(IProducterStream& stream) : ConsumerParser(stream)
{}
#include <iostream>
bool ParserHttp::readHttp(std::string& method, std::string& url, std::map< std::string, std::string >& header, std::string& content)
{
  beginCapture("method");
  if (readIgnoreCase("OPTIONS") || readIgnoreCase("GET") || readIgnoreCase("HEAD") || readIgnoreCase("POST") || readIgnoreCase("PUT") || readIgnoreCase("DELETE") || readIgnoreCase("TRACE") || readIgnoreCase("CONNECT"))
    {
      endCapture("method", method);
      readLWS();
      bool cont = false;
      beginCapture("url");
      while (read('/') || read('.') || read('?') || read('%') || read('&')
	     || read('=') || read('+') || read(':') || read('-')
	     || readRange('a', 'z') || readRange('A', 'Z') || readRange('0', '9'))
	cont = true;
      endCapture("url", url);
      readLWS();
      if (cont && readIgnoreCase("HTTP/1.1") && readCRLF())
	{
	  cont = true;
	  while (!(readCRLF() || readEOF()) && cont)
	    {
	      cont = false;
	      if (beginCapture("name"))
		{
		  std::string name, value;
		  bool cont2 = false;
		  while (read('-') || readRange('a', 'z') || readRange('A', 'Z'))
		    cont2 = true;
		  if (cont2 && endCapture("name", name) && (readLWS() || true) && read(':') && (readLWS() || true))
		    {
		      // Trouver comment faire un readUntil() sur plusieurs textes possibles
		      // if (beginCapture("value") && readUntil("\r\n") && endCapture("value", value))
		      if (beginCapture("value") && readUntilCRLF() && endCapture("value", value))
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
  return (read("\r\n") || read('\r') || read('\n'));
}

bool ParserHttp::readUntilCRLF()
{
  std::vector< std::string > crlf(3);
  crlf[0] = "\r\n";
  crlf[1] = "\r";
  crlf[2] = "\n";
  return readUntil(crlf);
}

bool ParserHttp::readLWS()
{
  saveContext();
  readCRLF();
  if (!(read(' ') || read('\t')))
    {
      restoreContext();
      return false;
    }
  validContext();
  while (read(' ') || read('\t'))
    ;
  return true;
}
