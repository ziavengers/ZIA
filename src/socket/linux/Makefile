NAME = $(ZIA_PATH)/lib/linux/socket/libsocket.so

all: $(NAME)

$(NAME): Socket.cpp
	@mkdir -p `dirname $@`
	g++ -shared -o $@ -fPIC $^ -I$(ZIA_PATH)/inc/ -I$(ZIA_PATH)/inc/linux/
