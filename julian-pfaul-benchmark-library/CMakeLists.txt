file(GLOB_RECURSE JULIAN_PFAUL_BENCHMARK_LIBRARY_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE JULIAN_PFAUL_BENCHMARK_LIBRARY_HEADERS CONFIGURE_DEPENDS src/*.h)

add_library(julian_pfaul_benchmark_library
        ${JULIAN_PFAUL_BENCHMARK_LIBRARY_SOURCES}
        ${JULIAN_PFAUL_BENCHMARK_LIBRARY_HEADERS}
)

target_include_directories(julian_pfaul_benchmark_library PUBLIC src)
target_link_libraries(julian_pfaul_benchmark_library PUBLIC julian_pfaul_library)