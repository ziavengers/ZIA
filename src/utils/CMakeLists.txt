project(libutils)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH}/${CMAKE_BUILD_TYPE})

add_library(
	utils
	SHARED
	Logger.cpp
	register.cpp
	${ARCH}/Library.cpp
	parsing/ConsumerParser.cpp
	parsing/FileStream.cpp
)

target_link_libraries(
	utils
	dl
	thread
)
