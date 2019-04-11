cmake_minimum_required (VERSION 3.8.2)

project(AudioIntrinsics)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# compiler flag
set(CMAKE_CXX_FLAGS_DEBUG "-Wall \
                           -Wextra \
                           -Werror \
                           -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall \
                             -Wextra \
                             -Werror \
                             -Ofast \
                             -funroll-loops \
                             -march=native")

# configure output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)

# target: libaudiointrinsics.so
set(LOCAL_MODULE audiointrinsics)

# source files
set(LOCAL_HDR_FILES "")
set(LOCAL_SRC_FILES src/dummy.cpp)

# include path
set(LOCAL_C_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LOCAL_EXPORT_C_INCLUDES ${LOCAL_C_INCLUDES})

# dependencies
set(LOCAL_STATIC_LIBRARIES "")
set(LOCAL_SHARED_LIBRARIES "")

add_library(${LOCAL_MODULE} SHARED ${LOCAL_HDR_FILES} ${LOCAL_SRC_FILES})

# include
target_include_directories(${LOCAL_MODULE} PUBLIC ${LOCAL_C_INCLUDES})

# linker
target_link_libraries(${LOCAL_MODULE} PUBLIC ${LOCAL_STATIC_LIBRARIES})
target_link_libraries(${LOCAL_MODULE} PUBLIC ${LOCAL_SHARED_LIBRARIES})

# testing
enable_testing()
add_subdirectory(test)
