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
      
	static HttpRequest build(IProducterStream   &stream);
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
