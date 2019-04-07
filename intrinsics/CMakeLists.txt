cmake_minimum_required (VERSION 3.8.2)

set(LOCAL_MODULE audiointrinsics)

set(LOCAL_SRC_FILES "main.cpp")

# dependencies
set(LOCAL_STATIC_LIBRARIES "")
set(LOCAL_SHARED_LIBRARIES "pthread")

# add_library(${LOCAL_MODULE} ${LOCAL_SRC_FILES})
add_executable(${LOCAL_MODULE} ${LOCAL_SRC_FILES})

# linker
target_link_libraries(${LOCAL_MODULE} ${LOCAL_STATIC_LIBRARIES})
target_link_libraries(${LOCAL_MODULE} ${LOCAL_SHARED_LIBRARIES})
