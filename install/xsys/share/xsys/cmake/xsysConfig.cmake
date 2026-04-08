# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_xsys_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED xsys_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(xsys_FOUND FALSE)
  elseif(NOT xsys_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(xsys_FOUND FALSE)
  endif()
  return()
endif()
set(_xsys_CONFIG_INCLUDED TRUE)

# output package information
if(NOT xsys_FIND_QUIETLY)
  message(STATUS "Found xsys: 0.0.1 (${xsys_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'xsys' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${xsys_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(xsys_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake")
foreach(_extra ${_extras})
  include("${xsys_DIR}/${_extra}")
endforeach()
