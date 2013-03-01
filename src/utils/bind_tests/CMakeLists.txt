project(testbind)

add_executable(
	nuts
	nuts.cpp
)

add_executable(
	test_bind
	main.cpp
)

target_link_libraries(
	nuts
	utils
)

target_link_libraries(
	test_bind
	utils
)
