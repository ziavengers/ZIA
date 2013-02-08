all: server client

client: client.cpp
	g++ $^ -o $@ -I$(ZIA_PATH)/inc/ -I$(ZIA_PATH)/inc/linux -L$(ZIA_PATH)/lib/linux/socket -lsocket -Wl,-rpath,$(ZIA_PATH)/lib/linux/socket

server: server.cpp
	g++ $^ -o $@ -I$(ZIA_PATH)/inc/ -I$(ZIA_PATH)/inc/linux -L$(ZIA_PATH)/lib/linux/socket -lsocket -Wl,-rpath,$(ZIA_PATH)/lib/linux/socket
