project(testObject)

include_directories(
	${ZIA_PATH}/inc/
	${ZIA_PATH}/inc/${ARCH}/
)
link_directories(
	${ZIA_PATH}/lib/${ARCH}/thread/
)

add_executable(
	test_Object
	main.cpp
	../Object.cpp
	../ThreadPool.cpp
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
