include_directories(${CMAKE_SOURCE_DIR} ${LIBLEVELDB_INCLUDE_DIR})

# .cxx sources
set (   leveldb_CXX
    	main.cpp
)
set(    leveldb_HEADERS
)

add_executable(leveldb ${leveldb_CXX} ${leveldb_HEADERS})
target_link_libraries(leveldb ${LIBLEVELDB_LIBRARIES})
