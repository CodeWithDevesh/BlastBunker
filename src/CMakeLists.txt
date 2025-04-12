file(GLOB_RECURSE SOURCES "*.cpp")

add_library(game STATIC ${SOURCES})
target_include_directories(game PUBLIC ../include ${RAYLIB_INCLUDE_DIRS})
target_link_libraries(game raylib ${RAYLIB_LIBRARIES})

add_executable(blastbunker main.cpp)
target_link_libraries(blastbunker game)
