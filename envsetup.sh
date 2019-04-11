#!/usr/bin/env bash

# path
export BUILD_TOP="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
export BUILD="${BUILD_TOP}/build"
export OUT="${BUILD}/out"

# navigation function
function cbuild() {
    cd ${BUILD}
}

function croot() {
    cd ${BUILD_TOP}
}

function cout() {
    cd ${OUT}
}
