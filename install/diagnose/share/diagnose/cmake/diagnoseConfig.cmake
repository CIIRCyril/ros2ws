# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_diagnose_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED diagnose_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(diagnose_FOUND FALSE)
  elseif(NOT diagnose_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(diagnose_FOUND FALSE)
  endif()
  return()
endif()
set(_diagnose_CONFIG_INCLUDED TRUE)

# output package information
if(NOT diagnose_FIND_QUIETLY)
  message(STATUS "Found diagnose: 0.0.0 (${diagnose_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'diagnose' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${diagnose_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(diagnose_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${diagnose_DIR}/${_extra}")
endforeach()
