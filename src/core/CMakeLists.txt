project(libcore)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH}/${CMAKE_BUILD_TYPE})

add_library(
	core
	SHARED
	Object.cpp
	Server.cpp
	ThreadPool.cpp
	Zia.cpp
)

target_link_libraries(
	core
	utils
	socket
)

add_executable(
	test_serv
	test_serv.cpp
)
target_link_libraries(
	test_serv
	core
)
