project(testsocket)

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
	thread
	utils
)
target_link_libraries(
	server
	socket
	thread
	utils
)
