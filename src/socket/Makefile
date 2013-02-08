all: server client

client: client.cpp linux/Socket.cpp
	g++ $^ -o $@ -I../../inc/ -I../../inc/linux

server: server.cpp linux/Socket.cpp
	g++ $^ -o $@ -I../../inc/ -I../../inc/linux
