project(testhttp)

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
