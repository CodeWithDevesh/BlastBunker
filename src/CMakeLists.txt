file(GLOB_RECURSE SOURCES "*.cpp")


find_package(Raylib REQUIRED)
find_package(Box2D REQUIRED)

add_library(game STATIC ${SOURCES})
target_include_directories(game PUBLIC ../include ${RAYLIB_INCLUDE_DIRS} ${BOX2D_INCLUDE_DIRS})
target_link_libraries(game raylib ${RAYLIB_LIBRARIES} ${BOX2D_LIBRARIES})

add_executable(blastbunker main.cpp)
target_link_libraries(blastbunker game)
