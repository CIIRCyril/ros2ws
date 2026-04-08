#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "body_control::dev_inspire_hand" for configuration ""
set_property(TARGET body_control::dev_inspire_hand APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(body_control::dev_inspire_hand PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdev_inspire_hand.so"
  IMPORTED_SONAME_NOCONFIG "libdev_inspire_hand.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS body_control::dev_inspire_hand )
list(APPEND _IMPORT_CHECK_FILES_FOR_body_control::dev_inspire_hand "${_IMPORT_PREFIX}/lib/libdev_inspire_hand.so" )

# Import target "body_control::dev_sri_6dof" for configuration ""
set_property(TARGET body_control::dev_sri_6dof APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(body_control::dev_sri_6dof PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdev_sri_6dof.so"
  IMPORTED_SONAME_NOCONFIG "libdev_sri_6dof.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS body_control::dev_sri_6dof )
list(APPEND _IMPORT_CHECK_FILES_FOR_body_control::dev_sri_6dof "${_IMPORT_PREFIX}/lib/libdev_sri_6dof.so" )

# Import target "body_control::glog_init" for configuration ""
set_property(TARGET body_control::glog_init APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(body_control::glog_init PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libglog_init.so"
  IMPORTED_SONAME_NOCONFIG "libglog_init.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS body_control::glog_init )
list(APPEND _IMPORT_CHECK_FILES_FOR_body_control::glog_init "${_IMPORT_PREFIX}/lib/libglog_init.so" )

# Import target "body_control::bodyctrl_component" for configuration ""
set_property(TARGET body_control::bodyctrl_component APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(body_control::bodyctrl_component PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libbodyctrl_component.so"
  IMPORTED_SONAME_NOCONFIG "libbodyctrl_component.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS body_control::bodyctrl_component )
list(APPEND _IMPORT_CHECK_FILES_FOR_body_control::bodyctrl_component "${_IMPORT_PREFIX}/lib/libbodyctrl_component.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
