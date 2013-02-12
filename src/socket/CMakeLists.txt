project(libsocket)

set(LIBRARY_OUTPUT_PATH ${ZIA_PATH}/lib/linux/socket/${CMAKE_BUILD_TYPE})
include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/linux/
)

add_library(
	socket
	SHARED
	Socket.cpp
)
