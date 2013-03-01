project(testhttp)

file(
	GLOB
	source_files
	*.cpp
)

add_executable(
	test_http
	${source_files}
)
	
target_link_libraries(
	test_http
	core
)
