project(testhttp)

include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/${ARCH}/
)
link_directories(${ZIA_PATH}/lib/${ARCH}/thread/)

file(
	GLOB
	source_files
	*.cpp
)

add_executable(
	test_http
	${source_files}
	${ZIA_PATH}/src/utils/Logger.cpp
	${ZIA_PATH}/src/thread/Locker.cpp
)
	
target_link_libraries(
	test_http
	thread
)
