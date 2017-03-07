
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

message("find_package(Boost)")
find_package(Boost COMPONENTS ${NEED_BOOST_COMPONENTS} REQUIRED)
message("BOOST_ROOT is ${BOOST_ROOT}")
