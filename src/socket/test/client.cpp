#define xstr(s) str(s)
#define str(s) #s

#include <stdlib.h>
#include <unistd.h>
#include "socket/Socket.hh"

int main(int ac, char** av)
{
  char buff[100];

  zia::network::ISocket* s = new zia::network::Socket();
  s->connect(av[1], atoi(av[2]));
  size_t len;
  while ((len = read(0, buff, 100)) > 0)
    s->write(buff, len);
  delete s;
}
