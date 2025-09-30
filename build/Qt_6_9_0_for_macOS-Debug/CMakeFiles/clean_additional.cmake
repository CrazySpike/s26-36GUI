# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/s26-36GUI_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/s26-36GUI_autogen.dir/ParseCache.txt"
  "s26-36GUI_autogen"
  )
endif()
