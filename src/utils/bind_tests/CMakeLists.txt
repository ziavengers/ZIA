project(testbind)

include_directories(
	${ZIA_PATH}/inc/
)

add_executable(
	nuts
	nuts.cpp
)

add_executable(
	test_bind
	main.cpp
)
