leveldb_bug_219
===============

This repository contain simple program to reproduce crash of leveldb, when not enough disk space.
See https://code.google.com/p/leveldb/issues/detail?id=219

===============
# Required:
* Cmake
* Leveldb

# Complilation:
cd build 
cmake -DCMAKE_BUILD_TYPE=debug .. 
make 

# Running of test:
1. Mount tmpfs
   # mount -t tmpfs tmpfs /tmp/leveldb -o size=500k
2. Run test program:
   $ ./build/src/leveldb /tmp/leveldb
