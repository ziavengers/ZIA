project(mod_SocketWriter)

set(LIBRARY_OUTPUT_PATH ${ZIA_MODS_PATH})

add_library(
	SocketWriter
	SHARED
	SocketWriter.cpp
)

target_link_libraries(
  utils
)

set_target_properties(
	SocketWriter
	PROPERTIES
	PREFIX ""
	SUFFIX .mod
)
