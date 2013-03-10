#include "http/RequestParser.hh"

#include <iostream>

namespace zia
{
  namespace http
  {

    RequestParser::RequestParser(zia::utils::parsing::IProducterStream& stream) : ConsumerParser(stream)
    {}

    // bool RequestParser::readHttp(std::string& method, std::string& url, std::map< std::string, std::string >& header, std::string& content)
    // {
    //   beginCapture("method");
    //   if (readIgnoreCase("OPTIONS") || readIgnoreCase("GET") || readIgnoreCase("HEAD") || readIgnoreCase("POST") || readIgnoreCase("PUT") || readIgnoreCase("DELETE") || readIgnoreCase("TRACE") || readIgnoreCase("CONNECT"))
    // 	{
    // 	  endCapture("method", method);
    // 	  readLWS();
    // 	  bool cont = false;
    // 	  beginCapture("url");
    // 	  while (read('/') || read('.') || read('?') || read('%') || read('&')
    // 		 || read('=') || read('+') || read(':') || read('-')
    // 		 || readRange('a', 'z') || readRange('A', 'Z') || readRange('0', '9'))
    // 	    cont = true;
    // 	  endCapture("url", url);
    // 	  readLWS();
    // 	  if (cont && readIgnoreCase("HTTP/1.1") && readCRLF())
    // 	    {
    // 	      cont = true;
    // 	      while (!(readCRLF() || readEOF()) && cont)
    // 		{
    // 		  cont = false;
    // 		  if (beginCapture("name"))
    // 		    {
    // 		      std::string name, value;
    // 		      bool cont2 = false;
    // 		      while (read('-') || readRange('a', 'z') || readRange('A', 'Z'))
    // 			cont2 = true;
    // 		      if (cont2 && endCapture("name", name) && (readLWS() || true) && read(':') && (readLWS() || true))
    // 			{
    // 			  if (beginCapture("value") && readUntilCRLF() && endCapture("value", value))
    // 			    {
    // 			      header[name] = value;
    // 			      cont = true;
    // 			    }
    // 			}
    // 		    }
    // 		}
    // 	      if (cont
    // 		  && beginCapture("content")
    // 		  && readUntilEOF()
    // 		  && endCapture("content", content))
    // 		return true;
    // 	    }
    // 	}
    //   method.clear();
    //   url.clear();
    //   header.clear();
    //   content.clear();
    //   return false;
    // }
    Request RequestParser::readHttp()
    {
      beginCapture("method");
      if (readIgnoreCase("OPTIONS") || readIgnoreCase("GET") || readIgnoreCase("HEAD") || readIgnoreCase("POST") || readIgnoreCase("PUT") || readIgnoreCase("DELETE") || readIgnoreCase("TRACE") || readIgnoreCase("CONNECT"))
	{
	  std::string method;
	  endCapture("method", method);
	  readLWS();
	  bool cont = false;
	  beginCapture("url");
	  while (read('/') || read('.') || read('?') || read('%') || read('&')
		 || read('=') || read('+') || read(':') || read('-')
		 || readRange('a', 'z') || readRange('A', 'Z') || readRange('0', '9'))
	    cont = true;
	  std::string url;
	  endCapture("url", url);
	  readLWS();
	  // Ajouter autres versions
	  if (cont && readIgnoreCase("HTTP/1.1") && readCRLF())
	    {
	      Request request(method, url);
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
			  if (beginCapture("value") && readUntilCRLF(false) && endCapture("value", value) && readCRLF())
			    {
			      request.header[name] = value;
			      cont = true;
			    }
			}
		    }
		}
	      if (cont
	      	  && beginCapture("content")
	      	  && readUntilEOF()
	      	  && endCapture("content", request.data()))
	      	{
	      	  return request;
	      	}
	    }
	}
      throw Exception("Error during parsing");
    }

    bool RequestParser::readCRLF()
    {
      return (read("\r\n") || read('\r') || read('\n'));
    }

    bool RequestParser::readUntilCRLF(bool contains)
    {
      std::vector< std::string > crlf(3);
      crlf[0] = "\r\n";
      crlf[1] = "\r";
      crlf[2] = "\n";
      return readUntil(crlf, contains);
    }

    bool RequestParser::readLWS()
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

  }
}
