set(LOCAL_MODULE audio_intrinsics_test)

find_package(GTest REQUIRED)

# source files
set(LOCAL_SRC_FILES utilstest/AudioAttributeTest.cpp
                    utilstest/AudioChannelMaskTest.cpp
                    utilstest/AudioFormatTest.cpp)

# include path
set(LOCAL_C_INCLUDES ${CMAKE_SOURCE_DIR}/include)

# dependencies
set(LOCAL_STATIC_LIBRARIES GTest::GTest
                           GTest::Main)
set(LOCAL_SHARED_LIBRARIES audiointrinsics)

add_executable(${LOCAL_MODULE} ${LOCAL_SRC_FILES})

# header
target_include_directories(${LOCAL_MODULE} PUBLIC ${LOCAL_C_INCLUDES})

# linker
target_link_libraries(${LOCAL_MODULE} PUBLIC ${LOCAL_STATIC_LIBRARIES})
target_link_libraries(${LOCAL_MODULE} PUBLIC ${LOCAL_SHARED_LIBRARIES})

# sub test cases
add_subdirectory(utilstest)
