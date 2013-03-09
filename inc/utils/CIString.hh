#ifndef UTILS_CISTRING_HH_
#define UTILS_CISTRING_HH_

#include <string>

namespace zia
{
  namespace utils
  {

    /*
      Case insensitive string class
     */

    class CIString : public std::string
    {
    public:
      CIString(const CIString& str) : std::string(str.data()) { }
      CIString(const std::string& str) : std::string(str) { }
      CIString(const char* str) : std::string(str) { }
      CIString(const std::string& str, size_t pos, size_t len = std::string::npos) : std::string(str, pos, len) { }
      CIString(const char* s, size_t n) : std::string(s, n) { }
      CIString(size_t n, char c) : std::string(n, c) { }
      template <class InputIterator>
      CIString(InputIterator first, InputIterator last) : std::string(first, last) {}

      size_t find(const std::string& str, size_t pos = 0) const;
      size_t find(const char* s, size_t pos = 0) const;
      size_t find(const char* s, size_t pos, size_t n) const;
      size_t find(char c, size_t pos = 0) const;


      size_t find_first_of(const std::string& str, size_t pos = 0) const;
      size_t find_first_of(const char* s, size_t pos = 0) const;
      size_t find_first_of(const char* s, size_t pos, size_t n) const;
      size_t find_first_of(char c, size_t pos = 0) const;

      size_t find_last_of(const std::string& str, size_t pos = npos) const;
      size_t find_last_of(const char* s, size_t pos = npos) const;
      size_t find_last_of(const char* s, size_t pos, size_t n) const;
      size_t find_last_of(char c, size_t pos = npos) const;


      size_t find_first_not_of(const std::string& str, size_t pos = 0) const;
      size_t find_first_not_of(const char* s, size_t pos = 0) const;
      size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
      size_t find_first_not_of(char c, size_t pos = 0) const;


      size_t find_last_not_of(const std::string& str, size_t pos = npos) const;
      size_t find_last_not_of(const char* s, size_t pos = npos) const;
      size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
      size_t find_last_not_of(char c, size_t pos = npos) const;

      int compare(const CIString& str) const;
      int compare(const std::string& str) const;
      // int compare(size_t pos, size_t len, const std::string& str) const;
      // int compare(size_t pos, size_t len, const std::string& str,
      // 		   size_t subpos, size_t sublen) const;
      int compare(const char* s) const;
      // int compare(size_t pos, size_t len, const char* s) const;
      // int compare(size_t pos, size_t len, const char* s, size_t n) const;

      bool operator==(const CIString& str) const;
      bool operator==(const std::string& str) const;
      bool operator==(const char* s) const;
    };


  }
}

#endif
