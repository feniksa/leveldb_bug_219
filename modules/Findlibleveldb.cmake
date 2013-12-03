find_path(LIBLEVELDB_INCLUDE_DIR leveldb/db.h
	HINTS /usr/local/include
    /home/feniks/workspace/libleveldb/include
	PATH_SUFFIXES leveldb
)
find_library(LIBLEVELDB_LIBRARY NAMES leveldb 
	HINTS /usr/local/lib /home/feniks/workspace/libleveldb/)

# handle the QUIETLY and REQUIRED arguments and set LIBLEVELDB_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LIBLEVELDB DEFAULT_MSG LIBLEVELDB_LIBRARY LIBLEVELDB_INCLUDE_DIR)

if(LIBLEVELDB_FOUND)
    set(LIBLEVELDB_LIBRARIES ${LIBLEVELDB_LIBRARY})
else(LIBLEVELDB_FOUND)
    set(LIBLEVELDB_LIBRARIES)
endif(LIBLEVELDB_FOUND)

mark_as_advanced(LIBLEVELDB_LIBRARY LIBLEVELDB_INCLUDE_DIR)
