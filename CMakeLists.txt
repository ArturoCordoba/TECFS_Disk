cmake_minimum_required(VERSION 3.8)
project(TECFS_Disk)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Parse.h DataStructures/LinkedList.h DataStructures/Node.h DataBaseHandler.cpp DataBaseHandler.h Singleton.cpp Singleton.h VideoHandler.cpp VideoHandler.h Parse.h)
add_executable(TECFS_Disk ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TECFS_Disk ${SFML_LIBRARIES})
endif()