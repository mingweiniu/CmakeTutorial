cmake_minimum_required (VERSION 3.5)

SET(PRROJ_NAME cmake_test_boost)

project (${PRROJ_NAME})
add_executable(${PRROJ_NAME} main.cpp)

include(${CMAKE_SOURCE_DIR}/cmake/Modules/getBoost.cmake)
if(Boost_FOUND)
	message("Boost_FOUND")
	message("include_directories(${BOOST_INCLUDE_DIRS})")
	include_directories(${BOOST_INCLUDE_DIRS})
	message("target_link_libraries(${PRROJ_NAME} ${BOOST_LIBRARIES})")
	target_link_libraries(${PRROJ_NAME} ${BOOST_LIBRARIES})

endif()

if(UNIX)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include  -Wall")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib")

endif()
