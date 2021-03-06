
# finding boost

message("boost setting multithread/static_libs/!static_runtime")
set(Boost_DEBUG ON) # Set to ON to enable debug output from FindBoost.
set(Boost_DETAILED_FAILURE_MSG ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME OFF)


if(WIN32)
	add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
	find_path(BOOST_ROOT NAMES boost/version.hpp HINTS
		"$ENV{BOOST_ROOT}"
		"$ENV{BOOSTROOT}"
	)

endif()

set(NEED_BOOST_COMPONENTS filesystem system)
message("find_package(Boost COMPONENTS ${NEED_BOOST_COMPONENTS} REQUIRED)")
find_package(Boost COMPONENTS ${NEED_BOOST_COMPONENTS} REQUIRED)
message("BOOST_ROOT is ${BOOST_ROOT}")

if(Boost_FOUND)
	#add_definitions(-DBOOST_ALL_NO_LIB)
	message("Boost_FOUND & set boost include/libs")
	set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
	set(PROJ_LIBRARIES ${PROJ_LIBRARIES} ${Boost_LIBRARIES})
endif()


