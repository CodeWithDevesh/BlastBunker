file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(bunkblaster ${SOURCES})
target_link_libraries(bunkblaster raylib box2d)