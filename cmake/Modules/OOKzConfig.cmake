INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_OOKZ OOKz)

FIND_PATH(
    OOKZ_INCLUDE_DIRS
    NAMES OOKz/api.h
    HINTS $ENV{OOKZ_DIR}/include
        ${PC_OOKZ_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    OOKZ_LIBRARIES
    NAMES gnuradio-OOKz
    HINTS $ENV{OOKZ_DIR}/lib
        ${PC_OOKZ_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OOKZ DEFAULT_MSG OOKZ_LIBRARIES OOKZ_INCLUDE_DIRS)
MARK_AS_ADVANCED(OOKZ_LIBRARIES OOKZ_INCLUDE_DIRS)

