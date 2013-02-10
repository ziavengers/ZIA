project(testhttp)

include_directories(
	${ZIA_PATH}/inc/
)

file(
	GLOB
	source_files
	*.cpp
)

add_executable(
	test
	${source_files}
)
	
