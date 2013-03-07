project(libcore)

set(LIBRARY_OUTPUT_PATH ${ZIA_LIBS_PATH})

add_library(
	core
	SHARED
	Object.cpp
	Server.cpp
	ThreadPool.cpp
	Settings.cpp
	Zia.cpp
	module/Module.cpp
	module/ModuleManagement.cpp
)

target_link_libraries(
	core
	utils
	socket
)
