set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

find_path (LIB_INCLUDES mylib.h ${CMAKE_SOURCE_DIR}/lib/mylib)
include_directories(${LIB_INCLUDES})
target_include_directories(${BINARY}_run PRIVATE ${CMAKE_SOURCE_DIR}/lib/mylib)
target_link_libraries(${BINARY}_run PRIVATE mylib)