project(libthread)

set(LIBRARY_OUTPUT_PATH ${ZIA_PATH}/lib/${ARCH}/thread/${CMAKE_BUILD_TYPE})
include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/${ARCH}/
)

add_library(
	thread
	SHARED
	${ARCH}/AThread.cpp
	${ARCH}/Mutex.cpp
	Locker.cpp
)
target_link_libraries(
	thread
	pthread
)
