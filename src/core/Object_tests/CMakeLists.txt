project(testObject)

add_executable(
	test_Object
	main.cpp
)
target_link_libraries(
	test_Object
	core
)

add_library(
	test
	SHARED
	lib.cpp
)
