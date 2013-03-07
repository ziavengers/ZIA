project(testhttp)

add_executable(
	test_http
	test.cpp
	TestProducterStream.cpp
	${ZIA_PATH}/src/http/HttpMessage.cpp
	${ZIA_PATH}/src/http/ParserHttp.cpp
)
	
target_link_libraries(
	test_http
	core
)
