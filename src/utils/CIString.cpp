#include "utils/CIString.hh"

#include <string.h>
#include <stdexcept>
#include <iostream>



namespace zia
{
  namespace utils
  {

    size_t	CIString::find(const CIString& str, size_t pos) const
    {
      return find(str.data(), pos);
    }

    size_t	CIString::find(const std::string& str, size_t pos) const
    {      
      return find(str.data(), pos);
    }

    size_t CIString::find(const char* s, size_t pos) const
    {
      return find(s, pos, strlen(s));
    }

    size_t CIString::find(const char* s, size_t pos, size_t n) const
    {
      size_t retmax, i, j, ret;

      if (pos > this->size())
	return std::string::npos;
      retmax = this->size() - strlen(s);
      for (ret = pos, j = 0; ret <= retmax; ++ret)
	{
	  for (i = ret, j = 0; i < this->size() &&
		 j < n && toupper(this->data()[i]) == toupper(s[j]);
	       ++i, ++j) ;
	  if (j == n)
	    return ret;
	}
      return std::string::npos;      
    }
    
    size_t CIString::find(char c, size_t pos) const
    {
      size_t retmax, j, ret;

      if (pos > this->size())
	return std::string::npos;
      retmax = this->size() - 1;
      for (ret = pos, j = 0; ret <= retmax; ++ret)
	{
	  if (toupper(this->data()[ret]) == toupper(c))
	    return ret;
	}
      return std::string::npos;
    }

    size_t CIString::find_first_of(const CIString& str, size_t pos) const
    {
      return find_first_of(str.data(), pos);
    }

    size_t CIString::find_first_of(const std::string& str, size_t pos) const
    {
      return find_first_of(str.data(), pos);
    }

    size_t CIString::find_first_of(const char* s, size_t pos) const
    {
      size_t slen = strlen(s);
      size_t retmax, ret, i, j;

      if (pos > this->size())
	return std::string::npos;
      retmax = this->size() - slen;
      for (ret = pos, j = 0; ret <= retmax; ++ret)
	{
	  bool loop = false;
	  for (i = ret, j = 0; j < slen && loop == false; ++j)
	    {
	      if (toupper(this->data()[i]) == toupper(s[j]))
		loop = true;
	    }
	  if (loop)
	    return ret;	    
	}
      return std::string::npos;      
    }

    size_t CIString::find_first_of(const char* s, size_t pos, size_t n) const
    { 
      size_t slen = strlen(s);
      size_t retmax, ret, i, j;

      if (pos > this->size())
	return std::string::npos;
      retmax = this->size() - slen;
      for (ret = pos, j = 0; ret <= retmax; ++ret)
	{
	  bool loop = false;
	  for (i = ret, j = 0; j < slen && j < n && loop == false; ++j)
	    {
	      if (toupper(this->data()[i]) == toupper(s[j]))
		loop = true;
	    }
	  if (loop)
	    return ret;	    
	}
      return std::string::npos;
    }
    
    size_t CIString::find_first_of(char c, size_t pos) const
    {
      return find(c, pos);
    }

    size_t CIString::find_last_of(const CIString& str, size_t pos) const
    {
      return find_last_of(str.data(), pos);
    }

    size_t CIString::find_last_of(const std::string& str, size_t pos) const
    {
      return find_last_of(str.data(), pos);
    }

    size_t CIString::find_last_of(const char* s, size_t pos) const
    {
      return find_last_of(s, pos, strlen(s));
    }

    size_t CIString::find_last_of(const char* s, size_t pos, size_t n) const
    {
      size_t slen = strlen(s);
      size_t j;
      int ret, i;

      if (pos != std::string::npos)
	ret = pos;
      else
	ret = this->size();
      for (j = 0; ret >= 0; --ret)
	{
	  bool loop = false;
	  for (i = ret, j = 0; j < slen && j < n && loop == false; ++j)
	    {
	      if (toupper(this->data()[i]) == toupper(s[j]))
	  	loop = true;
	    }
	  if (loop)
	    return ret;	    
	}
      return std::string::npos;
    }
    
    size_t CIString::find_last_of(char c, size_t pos) const
    {
      int j, ret;

      if (pos != std::string::npos)
	ret = pos;
      else
	ret = this->size();
      for (ret = pos, j = 0; ret >= 0; --ret)
	{
	  if (toupper(this->data()[ret]) == toupper(c))
	    return ret;
	}
      return std::string::npos;
    }

    size_t CIString::find_first_not_of(const CIString& str, size_t pos) const
    {
      return find_first_not_of(str.data(), pos);
    }
    
    size_t CIString::find_first_not_of(const std::string& str, size_t pos) const
    {
      return find_first_not_of(str.data(), pos);
    }

    size_t CIString::find_first_not_of(const char* s, size_t pos) const
    {
      return find_first_not_of(s, pos, strlen(s));
    }

    size_t CIString::find_first_not_of(const char* s, size_t pos, size_t n) const
    {
      size_t slen = strlen(s);
      size_t retmax, ret, i, j;

      if (pos > this->size())
	return std::string::npos;
      retmax = this->size() - slen;
      for (ret = pos, j = 0; ret <= retmax; ++ret)
	{
	  bool loop = false;
	  for (i = ret, j = 0; j < slen && j < n; ++j)
	    {
	      if (toupper(this->data()[i]) != toupper(s[j]))
		loop = true;
	      else
		{
		  loop = false;
		  break;
		}
	    }
	  if (loop)
	    return ret;
	}
      return 0;
    }

    size_t CIString::find_first_not_of(char c, size_t pos) const
    {
      size_t retmax, j, ret;

      if (pos > this->size())
	return std::string::npos;
      retmax = this->size() - 1;
      for (ret = pos, j = 0; ret <= retmax; ++ret)
	{
	  if (toupper(this->data()[ret]) != toupper(c))
	    return ret;
	}
      return 0;
    }

    size_t CIString::find_last_not_of(const CIString& str, size_t pos) const
    {
      return find_last_not_of(str.data(), pos);
    }
 
    size_t CIString::find_last_not_of(const std::string& str, size_t pos) const
    {
      return find_last_not_of(str.data(), pos);
    }

    size_t CIString::find_last_not_of(const char* s, size_t pos) const
    {
      return find_last_not_of(s, pos, strlen(s));
    }

    size_t CIString::find_last_not_of(const char* s, size_t pos, size_t n) const
    {
      size_t slen = strlen(s);
      size_t j;
      int ret, i;


      if (pos != std::string::npos)
	ret = pos;
      else
	ret = this->size() - 1;
      for (j = 0; ret >= 0; --ret)
	{
	  bool loop = false;
	  for (i = ret, j = 0; j < slen && j < n; ++j)
	    {
	      if (toupper(this->data()[i]) != toupper(s[j]))
		loop = true;
	      else
		{
		  loop = false;
		  break;
		}
	    }
	  if (loop)
	    return ret;
	}
      return 0;
    }

    size_t CIString::find_last_not_of(char c, size_t pos) const
    {
      int j, ret;

      if (pos != std::string::npos)
	ret = pos;
      else
	ret = this->size() - 1;
      for (j = 0; ret >= 0; --ret)
	{
	  if (toupper(this->data()[ret]) != toupper(c))
	    return ret;
	}
      return 0;
    }

    int CIString::compare(const CIString& str) const
    {
      return compare(str.data());
    }

    int CIString::compare(const std::string& str) const
    {
      return compare(str.data());
    }

    // int CIString::compare(size_t pos, size_t len, const std::string& str) const
    // {
    //   return compare(pos, len, str.data());
    // }

    // int CIString::compare(size_t pos, size_t len, const std::string& str,
    // 		size_t subpos, size_t sublen) const
    // {      
    // }
    
    int CIString::compare(const char* s) const
    {
      size_t i, len, j;

      for (i = 0, j = 0, len = strlen(s);
	   i < len && j < this->size();
	   i++, j++)
	{
	  if (this->data()[j] != s[i])
	    break;
	}
      if (this->data()[j] < s[i])
	return -1;
      else if (this->data()[j] > s[i])
	return 1;
      return 0;
    }


    // int CIString::compare(size_t pos, size_t l, const char* s) const
    // {
    //   size_t i, len, j;

    //   if (l == std::string::npos)
    // 	l = strlen(s);
    //   if (pos > strlen(s))
    // 	throw std::out_of_range("CIString::compare");
    //   for (i = pos, j = 0, len = strlen(s);
    // 	   i < len && i < l && j < this->size();
    // 	   i++, j++)
    // 	{
    // 	  if (this->data()[j] != s[i])
    // 	    break;
    // 	}      
    //   if (this->data()[j] > s[i])
    // 	return -1;
    //   else if (this->data()[j] < s[i])
    // 	return 1;
    //   return 0;
    // }
    
    // int CIString::compare(size_t pos, size_t len, const char* s, size_t n) const
    // {
      
    // }

    bool CIString::operator==(const CIString& str) const
    {
      if (compare(str) == 0)
	return true;
      return false;
    }

    bool CIString::operator==(const std::string& str) const
    {
      if (compare(str) == 0)
	return true;
      return false;
    }

    bool CIString::operator==(const char* s) const
    {
      if (compare(s) == 0)
	return true;
      return false;
    }
   
    
  }
}

