#ifndef _HTTPMESSAGE_H_
#define _HTTPMESSAGE_H_


#include <map>
#include <string>

class HttpMessageFactory
{

public:
  template < typename T >
  static T build(const std::string rawMessage)
  {
    return new T;
  }
};


class HttpHeader : public std::map< std::string, std::string>
{
  ;
};

class HttpMessage
{
public:
  HttpHeader header;
  std::string message;
  
  std::string toString(void);

};


class HttpRequest : public HttpMessage
{/*
   requete http
  */
  ;
};

class HttpReply : public HttpMessage
{/*
   reponse http
  */ 
  ;
};

#endif /* _HTTPMESSAGE_H_ */
