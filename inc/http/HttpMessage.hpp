#ifndef _HTTPMESSAGE_H_
#define _HTTPMESSAGE_H_


#include <map>
#include <string>


#include "utils/parsing/IProducterStream.hh"
#include "ParserHttp.hh"

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
      protected:
	std::string _content; //TOFIX : ref 

      public:
	virtual ~HttpMessage() { ; }
	HttpHeader header;
	std::string toString(void); //TO IMPL, see .cpp
	void	content(std::string &content)
	{
	  this->_content = content;
	}
	std::string &content()
	{
	  return this->_content;
	}
	

      };
      

      class HttpRequest : public HttpMessage
      {// http request modelisation


      public:
	const std::string _method; // TOFIX : ref bug
	const std::string  _url;  // TOFIX : ---^
	
	HttpRequest(const std::string & method, const std::string & url) : _method(method), _url(url){;}
      
	static HttpRequest build(zia::utils::parsing::IProducterStream   &stream);
      };
      
      class HttpReply : public HttpMessage
      {// http reply modelisation
	
      private:
	int _reply_code; //TOFIX : private
      };
    }
  }
}


#endif /* _HTTPMESSAGE_H_ */
