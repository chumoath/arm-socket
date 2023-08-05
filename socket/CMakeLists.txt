aux_source_directory(src SRC)
add_executable(arm-socket ${SRC})

install(TARGETS arm-socket DESTINATION app)