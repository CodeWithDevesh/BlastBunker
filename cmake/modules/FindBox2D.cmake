# Find Box2D include and library
# Defines:
#   BOX2D_FOUND
#   BOX2D_INCLUDE_DIRS
#   BOX2D_LIBRARIES

find_path(BOX2D_INCLUDE_DIR
    NAMES Box2D/Box2D.h box2d/box2d.h
    PATHS
        /usr/local/include
        /usr/include
        ${CMAKE_SOURCE_DIR}/external/box2d/include
        $ENV{BOX2D_DIR}/include
        C:/box2d/include
        C:/libs/box2d/include
)

find_library(BOX2D_LIBRARY
    NAMES box2d Box2D box2d.lib Box2D.lib
    PATHS
        /usr/local/lib
        /usr/lib
        ${CMAKE_SOURCE_DIR}/external/box2d/lib
        $ENV{BOX2D_DIR}/lib
        C:/box2d/lib
        C:/libs/box2d/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Box2D DEFAULT_MSG BOX2D_LIBRARY BOX2D_INCLUDE_DIR)

if (BOX2D_FOUND)
    set(BOX2D_LIBRARIES ${BOX2D_LIBRARY})
    set(BOX2D_INCLUDE_DIRS ${BOX2D_INCLUDE_DIR})
endif()
