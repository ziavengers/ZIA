project(zia)

set(ZIA_PATH, ${CMAKE_SOURCE_DIR})

#execute_process(COMMAND
#	"cd inc/utils/bind && ./generate.py 6"
#)
#execute_process(
#	COMMAND
#	cd inc/utils/bind
#	COMMAND
#	./generate.py
#)
add_subdirectory(inc/utils/bind)

add_subdirectory(src/socket/linux)
add_subdirectory(src/socket/)
add_subdirectory(src/utils/bind_tests)
add_subdirectory(src/parsing_http)
