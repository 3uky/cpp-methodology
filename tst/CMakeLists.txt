set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

include_directories(${PROJECT_SOURCE_DIR}/src/algorithms)
include_directories(${PROJECT_SOURCE_DIR}/src/algorithms/binary_tree)
include_directories(${PROJECT_SOURCE_DIR}/src/algorithms/sort)
include_directories(${PROJECT_SOURCE_DIR}/src/basic)
include_directories(${PROJECT_SOURCE_DIR}/src/basic/paradigms)
include_directories(${PROJECT_SOURCE_DIR}/src/basic/containers)
include_directories(${PROJECT_SOURCE_DIR}/src/basic/elements)
include_directories(${PROJECT_SOURCE_DIR}/src/basic/internals)
include_directories(${PROJECT_SOURCE_DIR}/src/basic/paradigms)
include_directories(${PROJECT_SOURCE_DIR}/src/basic/parallel)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code/dependency_inversion)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code/open_close_principle)
include_directories(${PROJECT_SOURCE_DIR}/src/clean_code/TDD)
include_directories(${PROJECT_SOURCE_DIR}/src/dangerous_constructions)
include_directories(${PROJECT_SOURCE_DIR}/src/design_patterns)
include_directories(${PROJECT_SOURCE_DIR}/src/exercises)

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gmock)
