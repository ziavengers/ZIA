#ifndef HTTP_MESSAGE_HPP_
#define HTTP_MESSAGE_HPP_

#include <map>
#include <string>
#include <iostream>

#include "utils/parsing/IProducterStream.hh"
#include "utils/register.hpp"

namespace zia
{
  namespace http
  {

    typedef std::map< std::string, std::string > Header;

    class Message
    {
    public:
      Message(const std::string& version = _httpVersion);
      virtual ~Message() {}
      const std::string& data() const;
      std::string& data();
      virtual std::string statusLine() const = 0;
      template < typename T >
      void write(T& stream) const
      {
	stream << statusLine() << _crlf;
	Header::const_iterator it;
	for (it = header.begin(); it != header.end(); ++it)
	  stream << it->first << " : " << it->second << _crlf;
	stream << _crlf;
	stream << _data;
      }
      TYPENAME(zia::http::Message);
      Header header;
    protected:
      std::string _data;
      std::string _version;
      static const std::string _crlf;
      static const std::string _httpVersion;
    };

  }
}


#endif
