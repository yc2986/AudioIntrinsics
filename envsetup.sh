#!/usr/bin/env bash

# path
export BUILD_TOP="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
export OUT="${BUILD_TOP}/build"

# navigation function
function croot() {
    cd ${BUILD_TOP}
}

function cout() {
    cd ${OUT}
}
