
message("setting boost multithread/static_libs/static_runtime")
SET(Boost_DEBUG ON) # Set to ON to enable debug output from FindBoost.
SET(Boost_DETAILED_FAILURE_MSG ON)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_STATIC_RUNTIME ON)


if(WiN32)
	add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
	find_path(BOOST_ROOT NAMES boost/version.hpp HINTS
		"$ENV{BOOST_ROOT}"
		"$ENV{BOOSTROOT}"
	)
endif()

message("find_package(Boost)")
find_package(Boost)
