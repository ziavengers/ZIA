project(testObject)

include_directories(
	${ZIA_PATH}/inc/
)

add_executable(
	test_Object
	main.cpp
	../Object.cpp
)
target_link_libraries(
	test_Object
	dl
)

add_library(
	test
	SHARED
	lib.cpp
)
