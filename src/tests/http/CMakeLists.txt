project(testhttp)

add_executable(
	test_http
	test.cpp
	TestProducterStream.cpp
)
	
target_link_libraries(
	test_http
	http
)
