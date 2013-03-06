project(test_module)

file(
	GLOB
	source_files
	*.cpp
)

add_executable(
	test_module
	${source_files}
)

target_link_libraries(
	test_module
	core
)

