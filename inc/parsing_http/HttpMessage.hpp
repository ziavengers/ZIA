#ifndef _HTTPMESSAGE_H_
#define _HTTPMESSAGE_H_


#include <map>
#include <string>


#include "parsing_http/IProducterStream.hh"
#include "parsing_http/ParserHttp.hh"

#include <iostream> //only for debug

namespace zia
{
  namespace http
  {
    namespace message
    {

      class HttpHeader : public std::map< std::string, std::string>
      {
      public:
	virtual ~HttpHeader() { ; }
      };

      class HttpMessage 
      {
      public:
	virtual ~HttpMessage() { ; }
	HttpHeader header;
	std::string _content; //TOFIX : private 
	std::string toString(void); //TO IMPL, see .cpp
      };
      

      class HttpRequest : public HttpMessage
      {// http request modelisation


      public:
	const std::string _method; // TOFIX : private
	const std::string  _url;  // TOFIX : private
	HttpRequest(const std::string &method, const std::string &url) : _method(method), _url(url){;}
      
	static HttpRequest build(IProducterStream   &stream)
	{ // parsing request processing, entry function.

	  ParserHttp p(stream);
	  std::string method;
	  std::string url;
	  std::map< std::string, std::string > header;
	  std::map< std::string, std::string >::iterator it;
	  std::string content;
	
	  HttpRequest message(method, url);

	  if (p.readHttp(method, url, header, content))
	    {	
	      for (it = header.begin(); it != header.end(); ++it)
		message.header[it->first] = it->second;

	      message._content = content;
	      return message;
	    }
	  //sinon, exception
	
	  HttpRequest t("bidon", "bidon");
	  return t;      
	}
      };
      
      class HttpReply : public HttpMessage
      {// http reply modelisation
	
      public:
	int _reply_code; //TOFIX : private
      };

      // class HttpMessage 
      // {
      // public:
      // 	virtual ~HttpMessage() { ; }

      // 	HttpHeader header;
      // 	std::string message;
  
      // 	std::string toString(void);

      // };


      // class HttpRequest : public HttpMessage
      // {//
      // 	// requete http
      // 	//
      // public :
      // 	std::string _content;
      // };

      // class HttpReply : public HttpMessage
      // {//
      // 	// reponse http
      // 	// 
      // 	;
      // };
    }
  }
}


#endif /* _HTTPMESSAGE_H_ */
