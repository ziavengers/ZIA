cmake_minimum_required(VERSION 2.8)
project(zia)

set(ZIA_PATH ${CMAKE_SOURCE_DIR})
set(ARCH linux)
set(ZIA_LIBS_PATH ${ZIA_PATH}/lib/${ARCH})

include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/${ARCH}/
)
link_directories(
	${ZIA_LIBS_PATH}
)

set(NB_BIND_PARAMS 6)

add_subdirectory(inc/utils/bind)
add_subdirectory(inc/core/Object)

add_subdirectory(src/socket/)
add_subdirectory(src/thread/)
add_subdirectory(src/utils/)
add_subdirectory(src/core/)

add_subdirectory(src/parsing_http)
add_subdirectory(src/socket/test)
add_subdirectory(src/utils/bind_tests)
add_subdirectory(src/core/Object_tests)
