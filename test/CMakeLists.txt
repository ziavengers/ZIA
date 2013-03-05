project(NutsModule)


add_library(
	NutsModule
	SHARED
	NutsModule.cpp
)

target_link_libraries(
  utils
)

