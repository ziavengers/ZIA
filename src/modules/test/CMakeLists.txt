project(NutsModule)

set(LIBRARY_OUTPUT_PATH ${ZIA_MODS_PATH})

add_library(
	NutsModule
	SHARED
	NutsModule.cpp
)

target_link_libraries(
  utils
)

set_target_properties(
	NutsModule
	PROPERTIES
	PREFIX ""
	SUFFIX .mod
)
