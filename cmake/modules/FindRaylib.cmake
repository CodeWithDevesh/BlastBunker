# Find raylib include and library
# Defines: 
#   RAYLIB_FOUND
#   RAYLIB_INCLUDE_DIRS
#   RAYLIB_LIBRARIES

find_path(RAYLIB_INCLUDE_DIR
    NAMES raylib.h
    PATHS
        /usr/local/include
        /usr/include
        ${CMAKE_SOURCE_DIR}/external/raylib/include
        $ENV{RAYLIB_DIR}/include
        C:/raylib/include
        C:/libs/raylib/include
)

find_library(RAYLIB_LIBRARY
    NAMES raylib raylib.lib
    PATHS
        /usr/local/lib
        /usr/lib
        ${CMAKE_SOURCE_DIR}/external/raylib/lib
        $ENV{RAYLIB_DIR}/lib
        C:/raylib/lib
        C:/libs/raylib/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Raylib DEFAULT_MSG RAYLIB_LIBRARY RAYLIB_INCLUDE_DIR)

if (RAYLIB_FOUND)
    set(RAYLIB_LIBRARIES ${RAYLIB_LIBRARY})
    set(RAYLIB_INCLUDE_DIRS ${RAYLIB_INCLUDE_DIR})
endif()
