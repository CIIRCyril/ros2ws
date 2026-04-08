# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_usb_sbus_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED usb_sbus_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(usb_sbus_FOUND FALSE)
  elseif(NOT usb_sbus_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(usb_sbus_FOUND FALSE)
  endif()
  return()
endif()
set(_usb_sbus_CONFIG_INCLUDED TRUE)

# output package information
if(NOT usb_sbus_FIND_QUIETLY)
  message(STATUS "Found usb_sbus: 1.1.5 (${usb_sbus_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'usb_sbus' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${usb_sbus_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(usb_sbus_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${usb_sbus_DIR}/${_extra}")
endforeach()
