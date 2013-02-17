project(object_generator)

add_custom_command(
	OUTPUT
	build
	COMMAND
	./generate.py ${NB_BIND_PARAMS} ${ZIA_PATH}
)
add_custom_target(
	object_generator
	ALL
	DEPENDS
	build
)
