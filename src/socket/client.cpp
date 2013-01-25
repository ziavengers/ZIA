#include <stdlib.h>
#include <unistd.h>
#include "Socket.hh"

int main(int ac, char** av)
{
  char buff[100];

  ISocket* s = new Socket();
  s->connect(av[1], atoi(av[2]));
  size_t len;
  while ((len = read(0, buff, 100)) > 0)
    s->write(buff, len);
  delete s;
}
