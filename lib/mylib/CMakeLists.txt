set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_library(mylib STATIC ${SOURCES})

target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
