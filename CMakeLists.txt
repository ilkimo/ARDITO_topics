cmake_minimum_required(VERSION 3.0)
project(ARDITO_topics)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(topics)
add_subdirectory(parser)



add_executable(sus main.cpp)

target_link_libraries(sus #target in which link
        parser #library name
        )

include_directories(${CMAKE_CURRENT_BINARY_DIR})

#include(CTest) # this adds a BUILD_TESTING which defaults to ON
#if(BUILD_TESTING)
#    add_subdirectory(tests)
#endif()