project(mod_SocketReader)

set(LIBRARY_OUTPUT_PATH ${ZIA_MODS_PATH})

add_library(
	SocketReader
	SHARED
	SocketReader.cpp
)

target_link_libraries(
  utils
)

set_target_properties(
	SocketReader
	PROPERTIES
	PREFIX ""
	SUFFIX .mod
)
