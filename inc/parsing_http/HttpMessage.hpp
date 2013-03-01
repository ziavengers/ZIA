#ifndef _HTTPMESSAGE_H_
#define _HTTPMESSAGE_H_


#include <map>
#include <string>

#include "parsing_http/IProducterStream.hh"
#include "parsing_http/ParserHttp.hh"

#include <iostream> //only for debug

namespace http
{
  namespace message
  {
    class HttpMessageFactory
    {

    public:
      // // // static HttpRequest build(IProducterStream   &stream)
      // // // { // parsing request processing, entry function.
      // // // 	HttpRequest message;

      // // // 	ParserHttp p(stream);
      // // // 	std::string method;
      // // // 	std::string url;
      // // // 	std::map< std::string, std::string > header;
      // // // 	std::map< std::string, std::string >::iterator it;
      // // // 	std::string content;
      // // // 	if (p.readHttp(method, url, header, content))
      // // // 	  {
      // // // 	    std::cout << "{" << method << "}" << std::endl;
      // // // 	    message.method = method;
      // // // 	    std::cout << "{" << url << "}" << std::endl;
      // // // 	    message.url = method;
      // // // 	    for (it = header.begin(); it != header.end(); ++it)
      // // // 	      std::cout << "-> " << it->first << " : " << it->second;
      // // // 	    std::cout << "{" << content << "}" << std::endl;
      // // // 	  }
	
      // // // 	T f;
	
	
      // // // 	return f; // empty request
      // // // }
      
      ;
    };


    class HttpHeader : public std::map< std::string, std::string>
    {
      // surcharger [] pour le get et le set
    public:
      virtual ~HttpHeader() { ; }
    };

    class HttpMessage 
    {
    public:
      virtual ~HttpMessage() { ; }

      HttpHeader header;
      std::string message;
  
      std::string toString(void);

    };


    class HttpRequest : public HttpMessage
    {//
     // requete http
     //

    public:
      const std::string _method; // ref + const
      const std::string  _url;    // ref + const

      HttpRequest(const std::string &method, const std::string &url) : _method(method), _url(url){;}
      
      static HttpRequest build(IProducterStream   &stream)
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
	
      	    for (it = header.begin(); it != header.end(); ++it)
      	      message.header[it->first] = it->second;

      	    // std::cout << "-> " << it->first << " : " << it->second;
      	    // std::cout << "{" << content << "}" << std::endl;
	    return message;
      	  }
      	//sinon, exception
	
	
	HttpRequest t("bidon", "bidon");
      	return t;//message;
      
      }
    };

    class HttpReply : public HttpMessage
    {//
     // reponse http
     //
      int reply_code;
      ;
    };
  }
}
#endif /* _HTTPMESSAGE_H_ */
