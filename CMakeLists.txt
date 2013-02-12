cmake_minimum_required(VERSION 2.8)
project(zia)

set(ZIA_PATH ${CMAKE_SOURCE_DIR})
set(NB_BIND_PARAMS 6)

add_subdirectory(inc/utils/bind)
add_subdirectory(src/socket/linux)
add_subdirectory(src/socket/)
add_subdirectory(src/utils/bind_tests)
add_subdirectory(src/parsing_http)