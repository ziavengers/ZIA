project(libutils)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH})

add_library(
	utils
	SHARED
	Logger.cpp
	Exception.cpp
	register.cpp
	random.cpp
	uuid.cpp
	${ARCH}/Library.cpp
	parsing/ConsumerParser.cpp
	parsing/FileStream.cpp
	ini/Ini.cpp
	ini/ReadIni.cpp
)

target_link_libraries(
	utils
	dl
	thread
)
