# - List of test programs:
set(FalaiseParticleIdentificationPlugin_TESTS
  test_topology_data.cxx
  test_base_topology_pattern.cxx
  test_tof_measurement.cxx
  test_vertex_measurement.cxx
  test_energy_driver.cxx
  test_angle_driver.cxx
  test_vertex_driver.cxx
  test_tof_driver.cxx
  test_tof_measurement_cut.cxx
  )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

foreach(_testsource ${FalaiseParticleIdentificationPlugin_TESTS})
  get_filename_component(_testname ${_testsource} NAME_WE)
  set(_testname "falaiseparticleidentificationplugin-${_testname}")
  add_executable(${_testname} ${_testsource})
  target_link_libraries(${_testname} Falaise_ParticleIdentification)
  # - On Apple, ensure dynamic_lookup of undefined symbols
  if(APPLE)
    set_target_properties(${_testname} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
  endif()
  add_test(NAME ${_testname} COMMAND ${_testname})
  set_property(TEST ${_testname}
    APPEND PROPERTY ENVIRONMENT ${_trackfit_TEST_ENVIRONMENT}
    )
  # - For now, dump them into the testing output directory
  set_target_properties(${_testname}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/fltests/modules
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/fltests/modules
    )
endforeach()

# end of CMakeLists.txt
