project(testsocket)

include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/${ARCH}/
)
link_directories(${ZIA_PATH}/lib/${ARCH}/socket/)

add_executable(
	client
	client.cpp
)
add_executable(
	server
	server.cpp
)

target_link_libraries(
	client
	socket
)
target_link_libraries(
	server
	socket
)
