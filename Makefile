all: bind socket http

bind:
	$(MAKE) -C src/utils/bind_tests/

socket:
	$(MAKE) -C src/socket/

http:
	$(MAKE) -C src/parsing_http/
