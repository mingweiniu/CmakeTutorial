cmake_minimum_required (VERSION 3.5)

add_executable(01GoogleTest "main.cpp")

#find googleTest
find_package(GTest)
if(GTEST_FOUND)
	include_directories(${GTEST_INCLUDE_DIRS})
	target_link_libraries(01GoogleTest ${GTEST_BOTH_LIBRARIES})
endif()

