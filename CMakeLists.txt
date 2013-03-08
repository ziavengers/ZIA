cmake_minimum_required(VERSION 2.8)
project(zia)

set(ZIA_PATH ${CMAKE_SOURCE_DIR})
IF( UNIX )
    set(ARCH linux)
ENDIF( UNIX )
IF( WIN32 )
    set(ARCH windows)
ENDIF( WIN32 )
set(ZIA_LIBS_PATH ${ZIA_PATH}/lib/${ARCH})
set(ZIA_MODS_PATH ${ZIA_PATH}/bin/modules/)
set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -g")

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

add_subdirectory(src/socket)
add_subdirectory(src/thread)
add_subdirectory(src/utils)
add_subdirectory(src/http)
add_subdirectory(src/core)

add_subdirectory(src/modules)

add_subdirectory(src/tests)
