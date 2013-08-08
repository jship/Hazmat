CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Hazmat_Unit_Tests)

# Build output directories.
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Install prefix.
SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})
IF(APPLE)
    SET(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/dist)
ENDIF()

# Append paths to custom CMake scripts.
LIST(APPEND CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/cmake/modules
    ${PROJECT_SOURCE_DIR}/cmake/utils
)

# Include custom target functions.
INCLUDE(CustomTargetCommands)

# Make sure system libs are installed.
INCLUDE(InstallRequiredSystemLibraries)

FIND_PACKAGE(TUT REQUIRED)
INCLUDE_DIRECTORIES(${TUT_INCLUDE_DIR})

# Project-specific include/link directories.
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/test)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

# Subdirectory containing unit tests.
ADD_SUBDIRECTORY(test)
