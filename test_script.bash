#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

mountpoint -q /tmp/leveldb || (mkdir -p /tmp/leveldb && sudo mount -t tmpfs tmpfs /tmp/leveldb -o size=500k)

#$DIR/build/src/leveldb /tmp/leveldb

