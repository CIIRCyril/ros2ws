#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "xsys::xsys_component" for configuration ""
set_property(TARGET xsys::xsys_component APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(xsys::xsys_component PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libxsys_component.so"
  IMPORTED_SONAME_NOCONFIG "libxsys_component.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS xsys::xsys_component )
list(APPEND _IMPORT_CHECK_FILES_FOR_xsys::xsys_component "${_IMPORT_PREFIX}/lib/libxsys_component.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
