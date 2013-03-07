project(libhttp)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH})

add_library(
	http
	SHARED
	HttpMessage.cpp
	ParserHttp.cpp
)

target_link_libraries(
	http
	utils
)
