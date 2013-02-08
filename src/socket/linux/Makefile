NAME = ../../../lib/linux/socket/libsocket.so

all: $(NAME)

$(NAME): Socket.cpp
	@mkdir -p `dirname $@`
	g++ -shared -o $@ -fPIC $^ -I../../../inc/ -I../../../inc/linux/
