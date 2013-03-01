#include "parsing_http/HttpMessage.hpp"


<<<<<<< HEAD
#include <fstream>
#include <iostream>

// c'est un long namespace
std::string http::message::HttpMessage::toString(void)
{
  // return a string-representation of the request, usefull
  // for crafting request.
  // - header -
  // - message -

  // prevoir les problemes qui vont apparaitres a cause des encodages...




  return std::string("not implemented bastard");
}
=======
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
>>>>>>> b836ab1aaabef4ec2db985cd8d44a8871c4efa8f

    }
  }
}


// void	testFromFile()
// {
//   std::ifstream file("./request_sample");

//   std::cout << "start" << std::endl;
//   std::string tmp;
//   while (file >> tmp)
//     {
//       std::cout << tmp << std::endl ;
//     }
// }
