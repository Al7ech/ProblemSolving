#!/bin/bash

TEST_OUT=$(g++ -std=c++11 $PWD/$1.cpp -o $PWD/../bin/$1 2>&1)

if [ ! -z "$TEST_OUT" ]; then
    echo "$TEST_OUT"
fi

if [[ $TEST_OUT != *"error"* ]]; then
  echo "compile clear"
  $PWD/../bin/$1
fi
