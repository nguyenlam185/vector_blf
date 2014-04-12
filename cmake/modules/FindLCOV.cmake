find_program(LCOV_EXECUTABLE lcov)
find_program(LCOV_GENHTML_EXECUTABLE genhtml)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LCOV DEFAULT_MSG LCOV_EXECUTABLE)
find_package_handle_standard_args(LCOV_GENHTML DEFAULT_MSG LCOV_GENHTML_EXECUTABLE)

mark_as_advanced(LCOV_EXECUTABLE)
mark_as_advanced(LCOV_GENHTML_EXECUTABLE)
