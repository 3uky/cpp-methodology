set(BINARY ${CMAKE_PROJECT_NAME}_tst)

include(GoogleTest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

include_directories(${PROJECT_SOURCE_DIR}/src/dsa/algorithms/search)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/algorithms/binary_tree)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/algorithms/sort)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/data_structures)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/data_structures/list)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/data_structures/queue)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/data_structures/stack)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/data_structures/tree)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/data_structures/graph)
include_directories(${PROJECT_SOURCE_DIR}/src/dsa/data_structures/my_container)
include_directories(${PROJECT_SOURCE_DIR}/src/cpp_language/basics)
include_directories(${PROJECT_SOURCE_DIR}/src/cpp_language/internals)
include_directories(${PROJECT_SOURCE_DIR}/src/cpp_language/parallel)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/clean_code)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/clean_code/dependency_inversion_principle)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/clean_code/open_closed_principle)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/clean_code/liskov_substitution_principle)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/clean_code/case_study/ocp_writer)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/clean_code/case_study/dip_expense_reporter)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/clean_code/case_study/tdd_bowling)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/design_patterns)
include_directories(${PROJECT_SOURCE_DIR}/src/abstraction/oop_paradigms)
include_directories(${PROJECT_SOURCE_DIR}/src/leet_code)

add_executable(${BINARY} ${TEST_SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gmock)

gtest_discover_tests(${BINARY})