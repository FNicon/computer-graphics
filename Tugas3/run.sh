#!/bin/bash

if [[ $1 == "--debug" ]]
then
    if ! grep -q "CMAKE_BUILD_TYPE:STRING=Debug" build/CMakeCache.txt > /dev/null 2>&1
    then
        rm -rf build
        echo "Previous build directory is removed." 1>&2
        echo 1>&2
    fi

    ./build.sh -DCMAKE_BUILD_TYPE=Debug
    echo "Project is built." 1>&2
    echo 1>&2

    sudo gdb build/src/main
else
    if grep -q "CMAKE_BUILD_TYPE:STRING=Debug" build/CMakeCache.txt > /dev/null 2>&1
    then
        rm -rf build
        echo "Previous build directory is removed." 1>&2
        echo 1>&2
    fi

    ./build.sh
    echo "Project is built." 1>&2
    echo 1>&2

    sudo build/src/main "$@"
fi
