#include "http/HttpMessage.hpp"



#include <fstream>
#include <iostream>

namespace zia
{
  namespace http
  {
    namespace message
    {
      std::string HttpMessage::toString(void)
      {
	// return a string-representation of the request, usefull
	// for crafting request.
	// - header -
	// - message -
	// prevoir les problemes qui vont apparaitres a cause des encodages...


  
	return std::string("not implemented bastard");
      }

      HttpRequest HttpRequest::build(zia::utils::parsing::IProducterStream   &stream)
      { // parsing request processing, entry function.

	ParserHttp p(stream);
	std::string method;
	std::string url;
	std::map< std::string, std::string > header;
	std::map< std::string, std::string >::iterator it;
	std::string content;

	if (p.readHttp(method, url, header, content))
	  {	
	
	    HttpRequest message(method, url);

	    // message._method = method;
	    // message._url = url;
	    for (it = header.begin(); it != header.end(); ++it)
	      message.header[it->first] = it->second;

	    //message._content = content;
	    message.content(content);
	    return message;
	  }
	//sinon, exception
	
	HttpRequest t("bidon", "bidon");
	return t;      
      }

    }
  }
}


