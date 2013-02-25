project(testsocket)

include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/${ARCH}/
)
link_directories(${ZIA_PATH}/lib/${ARCH}/socket/)

add_executable(
	client
	client.cpp
	${ZIA_PATH}/src/utils/Logger.cpp
)
add_executable(
	server
	server.cpp
	${ZIA_PATH}/src/utils/Logger.cpp
)

target_link_libraries(
	client
	socket
	thread
)
target_link_libraries(
	server
	socket
	thread
)
