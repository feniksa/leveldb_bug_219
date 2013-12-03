project(leveldb)

cmake_minimum_required(VERSION 2.6.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules/")

find_package(libleveldb)
if (NOT LIBLEVELDB_FOUND)
	message (FATAL_ERROR "libleveldb not found")
endif()

add_definitions(
    -std=c++11 # Or -std=c++0x
)

add_subdirectory(src)
