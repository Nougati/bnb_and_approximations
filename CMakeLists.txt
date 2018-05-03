cmake_minimum_required(VERSION 2.6)

#Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# What am I doing?
set(SOURCE ./branch_and_bound_short_correctness_test.cpp ./branch_and_bound.c ./pisinger_reader.c ./fptas.c) 


# Link runTests with what we want to test and the GTest and pthread library
add_executable(shortTests ${SOURCE})
#add_executable(runTests branch_and_bound_short_correctness_test.cpp)
target_link_libraries(shortTests ${GTEST_LIBRARIES} pthread)

