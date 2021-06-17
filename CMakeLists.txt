cmake_minimum_required(VERSION 3.16)
project(HlkLog VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS src/*.h)

# Shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(Hlk::Log ALIAS ${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/hlk/log>
)

if (BUILD_TEST)
    add_subdirectory(test)
endif()

set_target_properties(
    ${PROJECT_NAME} PROPERTIES 
        PUBLIC_HEADER "${HEADERS}"
        EXPORT_NAME Log
        # VERSION ${PROJECT_VERSION}
)

# Install library and headers
install(
    TARGETS ${PROJECT_NAME} 
    EXPORT ${PROJECT_NAME}Targets
        PUBLIC_HEADER 
            DESTINATION include/hlk/log
        ARCHIVE 
            DESTINATION lib 
        LIBRARY 
            DESTINATION lib 
        RUNTIME 
            DESTINATION bin)

# Generate base config and install
install(
    EXPORT ${PROJECT_NAME}Targets
    NAMESPACE Hlk::
    FILE ${PROJECT_NAME}Config.cmake 
    DESTINATION lib/cmake/${PROJECT_NAME})

# Generate version config
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

# Install version config
install(
    FILES
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)