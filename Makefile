ZIA_PATH = $(shell pwd)

all: libsocket bind socket http

libsocket:
	$(MAKE) -C src/socket/linux/ ZIA_PATH=$(ZIA_PATH)

bind:
	$(MAKE) -C src/utils/bind_tests/ ZIA_PATH=$(ZIA_PATH)

socket:
	$(MAKE) -C src/socket/ ZIA_PATH=$(ZIA_PATH)

http:
	$(MAKE) -C src/parsing_http/ ZIA_PATH=$(ZIA_PATH)
