all: server client

client: client.cpp
	g++ $^ -o $@ -I../../inc/ -I../../inc/linux -L../../lib/linux/socket -lsocket -Wl,-rpath,../../lib/linux/socket

server: server.cpp
	g++ $^ -o $@ -I../../inc/ -I../../inc/linux -L../../lib/linux/socket -lsocket -Wl,-rpath,../../lib/linux/socket
