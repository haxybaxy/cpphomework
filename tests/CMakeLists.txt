include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)
# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)

add_executable(test13 test13.cpp) # Compile a test source
add_executable(test14 test14.cpp) # Compile a test source
add_executable(test15 test15.cpp) # Compile a test source
# Link against any required libraries. The library "some_library" is compiled in src/
target_link_libraries(test13 main13)
target_link_libraries(test14 main14)
target_link_libraries(test15 main15)
gtest_discover_tests(test13)            # Register the tests to gtest
gtest_discover_tests(test14)            # Register the tests to gtest
gtest_discover_tests(test15)            # Register the tests to gtest