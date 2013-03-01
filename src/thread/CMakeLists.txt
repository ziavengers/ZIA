project(libthread)

set(LIBRARY_OUTPUT_PATH ${ZIA_PATH}/lib/${ARCH}/${CMAKE_BUILD_TYPE})

add_library(
	thread
	SHARED
	${ARCH}/AThread.cpp
	${ARCH}/Mutex.cpp
	${ARCH}/CondVar.cpp
	Locker.cpp
)
target_link_libraries(
	thread
	pthread
)
