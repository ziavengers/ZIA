#include "utils/register.hpp"

namespace zia
{
  namespace utils
  {

    std::list< TypeNames::IRegistered* > TypeNames::_types;

  }
}

#include <string>

class RegisterCommonTypes
{
public:
  RegisterCommonTypes()
  {
    registerType(char);
    registerType(int);
    registerType(long);
    registerType(float);
    registerType(double);
    registerType(unsigned char);
    registerType(unsigned int);
    registerType(unsigned long);
    registerType(char*);
    registerType(const char*);
    registerType(int*);
    registerType(std::string);
    registerType(std::string&);
    registerType(const std::string&);
  }
};
static RegisterCommonTypes _;
