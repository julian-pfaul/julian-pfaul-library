cmake_minimum_required(VERSION 3.10)

project(JULIAN_PFAUL_LIBRARY)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.h")

set(CMAKE_CXX_STANDARD 23)

add_library(julian_pfaul_library STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(julian_pfaul_library PUBLIC ${CMAKE_SOURCE_DIR}/src)