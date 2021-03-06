cmake_minimum_required(VERSION 2.8)
project(cnet)

SET (CMAKE_CXX_COMPILER             "/usr/bin/g++")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g -Wall")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O2 -DNDEBUG -fstrict-aliasing -ffast-math -march=native")

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

include_directories(rarray)

add_definitions(-std=c++11)

if (NOT EXISTS "src/cmdline.c" AND NOT EXISTS "src/cmdline.h")
  message("** Command line parser source files not found. Creating gengetopt rules ...")

	# Check if gengetopt is installed
	find_program(GENGETOPT gengetopt)
	if (NOT GENGETOPT)
		message(FATAL_ERROR "Unable to find gengetopt")
	endif (NOT GENGETOPT)

	set(GGO_FILES src/cmdline.h src/cmdline.cc)
	add_custom_command (
    OUTPUT    ${GGO_FILES}
		COMMAND		gengetopt -i src/command.ggo --output-dir src -G -c cc
		DEPENDS 	src/command.ggo
		COMMENT		"Generating getopt parser code (cmdline.*) ..."
		VERBATIM
	)
  add_custom_target(ggotarget ALL DEPENDS ${GGO_FILES})
endif (NOT EXISTS "src/cmdline.c" AND NOT EXISTS "src/cmdline.h")

set(LEARNCLTREE_SOURCES src/cltree.cc src/cltree.h src/dataset.cc src/dataset.h src/learncltree.cc src/utils.h)
set(LEARNCNET_SOURCES src/bernoulli.h src/bernoulli.cc src/mix_bernoulli.h src/mix_bernoulli.cc src/cltree.cc
src/cltree.h src/dataset.cc src/dataset.h src/utils.h src/cmdline.cc
src/cmdline.h src/cnet.h src/globals.h src/learncnet.cc src/nodes.cc src/nodes.h src/params.cc src/params.h)
set(LEARNENSCNET_SOURCES src/bernoulli.h src/bernoulli.cc src/mix_bernoulli.h src/mix_bernoulli.cc src/cltree.cc
src/cltree.h src/dataset.cc src/dataset.h src/utils.h src/cmdline.cc
src/cmdline.h src/cnet.h src/globals.h src/learnenscnet.cc src/nodes.cc src/nodes.h src/params.cc src/params.h)


add_executable(learncltree ${LEARNCLTREE_SOURCES})
add_executable(learncnet ${LEARNCNET_SOURCES})
add_executable(learnenscnet ${LEARNENSCNET_SOURCES})


