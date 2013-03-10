project(libhttp)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH})

add_library(
	http
	SHARED
	Message.cpp
	Request.cpp
	Response.cpp
	RequestParser.cpp
)

target_link_libraries(
	http
	utils
)
