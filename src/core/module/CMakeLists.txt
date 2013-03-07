project(test_module)

add_executable(
	test_module
	test_module.cpp
)

target_link_libraries(
	test_module
	core
)

