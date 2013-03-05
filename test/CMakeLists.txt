project(libNutsModule)


add_library(
	SHARED
	NutsModule.cpp
)

target_link_libraries(
	thread
)
