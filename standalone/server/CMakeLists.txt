set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(server ${SOURCES})

target_include_directories(server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})