cmake_minimum_required(VERSION 3.15)
project(rodeo_race)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts")

#add_executable(cv_threads cv_threads.cpp)
#target_link_libraries(cv_threads pthread)

#add_executable(custom_mutex custom_mutex.cpp)
#target_link_libraries(custom_mutex pthread)

add_executable(safe_queue safe_queue.cpp)
target_link_libraries(safe_queue pthread)
