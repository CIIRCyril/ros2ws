# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dev_inspire_hand_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dev_inspire_hand_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dev_inspire_hand_FOUND FALSE)
  elseif(NOT dev_inspire_hand_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dev_inspire_hand_FOUND FALSE)
  endif()
  return()
endif()
set(_dev_inspire_hand_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dev_inspire_hand_FIND_QUIETLY)
  message(STATUS "Found dev_inspire_hand: 0.0.0 (${dev_inspire_hand_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dev_inspire_hand' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dev_inspire_hand_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dev_inspire_hand_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dev_inspire_hand_DIR}/${_extra}")
endforeach()
