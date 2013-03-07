project(libthread)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH})

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
