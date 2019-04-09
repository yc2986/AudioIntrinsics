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
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# subdirectory
add_subdirectory(external)
add_subdirectory(intrinsics)
