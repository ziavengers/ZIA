cmake_minimum_required(VERSION 2.8)
project(zia)

set(ZIA_PATH ${CMAKE_SOURCE_DIR})
set(ARCH linux)

set(NB_BIND_PARAMS 6)

add_subdirectory(inc/utils/bind)
add_subdirectory(inc/core/Object)
add_subdirectory(src/socket/)
add_subdirectory(src/thread/)
add_subdirectory(src/parsing_http)

add_subdirectory(src/socket/test)
add_subdirectory(src/utils/bind_tests)
add_subdirectory(src/core/Object_tests)
