all: server client

client: client.cpp Socket.cpp
	g++ $^ -o $@ -I../../../inc/

server: server.cpp Socket.cpp
	g++ $^ -o $@ -I../../../inc/
