# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\a_89_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\a_89_autogen.dir\\ParseCache.txt"
  "a_89_autogen"
  )
endif()
