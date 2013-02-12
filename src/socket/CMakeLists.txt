project(libsocket)

set(LIBRARY_OUTPUT_PATH ${ZIA_PATH}/lib/${ARCH}/socket/${CMAKE_BUILD_TYPE})
include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/${ARCH}/
)

add_library(
	socket
	SHARED
	${ARCH}/Socket.cpp
)
