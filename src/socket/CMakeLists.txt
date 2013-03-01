project(libsocket)

set(LIBRARY_OUTPUT_PATH ${ZIA_PATH}/lib/${ARCH}/${CMAKE_BUILD_TYPE})

add_library(
	socket
	SHARED
	${ARCH}/Socket.cpp
)
