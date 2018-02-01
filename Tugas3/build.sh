#!/bin/sh

mkdir -p build
cd build

if command -v ninja > /dev/null 2>&1; then
  cmake .. -G Ninja "$@"
  ninja
else
  cmake .. "$@"
  make
fi
