#include <stdlib.h>
#include <iostream>
#include "Socket.hh"

int main(int ac, char** av)
{
  ISocket* s = new Socket();
  s->bind(atoi(av[1]));
  s->listen(1);
  ISocket* c = s->accept();

  char buff[100];
  while (c->read(buff, 100) > 0)
    std::cout << buff;
  delete c;
  delete s;
}
