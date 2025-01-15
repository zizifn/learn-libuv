cmake_minimum_required (VERSION 3.10)

project (learn_libuv C)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g")

# custom target to clean all files in build directory
add_custom_target(clean-all
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/*
)

# Find all source files in src directory and src/modules directory
file(GLOB SRC_FILES 
    "${CMAKE_SOURCE_DIR}/src/*.c"
    "${CMAKE_SOURCE_DIR}/src/modules/*.c"
)

set(LEARN_LIBUV_SOURCE 
    ${SRC_FILES}
)

add_subdirectory(deps/libuv ${CMAKE_BINARY_DIR}/libuv)


# target
# add_executable( ${PROJECT_NAME} ${LEARN_LIBUV_SOURCE})

# Add executable for event_order.c
add_executable(${PROJECT_NAME} src/event_order.c)
target_link_libraries(${PROJECT_NAME} PRIVATE uv)

# Add executable for event_order2.c
add_executable(main2 src/main2.c)
target_link_libraries(main2 PRIVATE uv)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
