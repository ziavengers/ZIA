cmake_minimum_required(VERSION 2.8)
project(zia)

set(ZIA_PATH ${CMAKE_SOURCE_DIR})
set(NB_BIND_PARAMS 6)

add_custom_command(
	OUTPUT
	inc/utils/bind/build
	COMMAND
	./generate.py ${NB_BIND_PARAMS}
	WORKING_DIRECTORY inc/utils/bind
)
add_custom_target(
	bind_generator
	ALL
	DEPENDS
	inc/utils/bind/build
)

add_subdirectory(src/socket/linux)
add_subdirectory(src/socket/)
add_subdirectory(src/utils/bind_tests)
add_subdirectory(src/parsing_http)
