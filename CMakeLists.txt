cmake_minimum_required(VERSION 3.5.0)
project(cpp-methodology VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)

add_subdirectory(tst)
add_subdirectory(src)

add_subdirectory(standalone/client)
add_subdirectory(standalone/server)

add_subdirectory(lib/mylib)
add_subdirectory(lib/googletest)

set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options asio date_time)
set(BOOST_ENABLE_CMAKE ON)