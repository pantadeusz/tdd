#!/bin/bash -e

cd $(dirname $0)
cd ..

D=$PWD

cd hsqldb-scripts
./server.sh &
SRVPID=$!
sleep 1s
cd $D
cd java-jdbc/hellojdbc
mvn test
kill $SRVPID

