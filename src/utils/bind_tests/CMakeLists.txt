project(testbind)

include_directories(
	${ZIA_PATH}/inc/
)

add_executable(
	nuts
	nuts.cpp
	${ZIA_PATH}/src/utils/register.cpp
)

add_executable(
	test_bind
	main.cpp
	${ZIA_PATH}/src/utils/register.cpp
)
