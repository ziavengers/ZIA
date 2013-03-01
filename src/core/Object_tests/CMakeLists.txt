project(testObject)

add_executable(
	test_Object
	main.cpp
	../Object.cpp
	../ThreadPool.cpp
	../../utils/Logger.cpp
	../../utils/register.cpp
)
target_link_libraries(
	test_Object
	dl
	thread
)

add_library(
	test
	SHARED
	lib.cpp
)
