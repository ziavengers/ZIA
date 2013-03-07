project(libsocket)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH})

add_library(
	socket
	SHARED
	${ARCH}/Socket.cpp
)
