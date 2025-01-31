set(BINARY ${CMAKE_PROJECT_NAME}_tst)

include(GoogleTest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

include_directories(${PROJECT_SOURCE_DIR}/src/algorithms/searching)
include_directories(${PROJECT_SOURCE_DIR}/src/algorithms/binary_tree)
include_directories(${PROJECT_SOURCE_DIR}/src/algorithms/sort)
include_directories(${PROJECT_SOURCE_DIR}/src/cpp_basic_constructs)
include_directories(${PROJECT_SOURCE_DIR}/src/cpp_internals)
include_directories(${PROJECT_SOURCE_DIR}/src/containers)
include_directories(${PROJECT_SOURCE_DIR}/src/parallel_programming)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code/dependency_inversion)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code/open_close_principle)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code/tdd)
include_directories(${PROJECT_SOURCE_DIR}/src/dangerous_constructions)
include_directories(${PROJECT_SOURCE_DIR}/src/design_patterns)
include_directories(${PROJECT_SOURCE_DIR}/src/leet_code)
include_directories(${PROJECT_SOURCE_DIR}/src/oop_paradigms)

add_executable(${BINARY} ${TEST_SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gmock)

gtest_discover_tests(${BINARY})