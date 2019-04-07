#!/usr/bin/env bash

# path
export BUILD_TOP="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
export BUILD_INTERMEDIATE_DIR="${BUILD_TOP}/.build"
export OUT="${BUILD_TOP}/build"

# navigation function
function croot() {
    cd ${BUILD_TOP}
}

function cartifact() {
    cd ${BUILD_INTERMEDIATE_DIR}
}

function cout() {
    cd ${OUT}
}
