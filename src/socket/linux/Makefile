all: server client

client: client.cpp Socket.cpp
	g++ $^ -o $@ -I../../../inc/socket/linux/

server: server.cpp Socket.cpp
	g++ $^ -o $@ -I../../../inc/socket/linux/
