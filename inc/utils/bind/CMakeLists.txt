project(bind_generator)

add_custom_command(
	OUTPUT
	build
	COMMAND
	./generate.py ${NB_BIND_PARAMS} ${ZIA_PATH}
)
add_custom_target(
	bind_generator
	ALL
	DEPENDS
	build
)
