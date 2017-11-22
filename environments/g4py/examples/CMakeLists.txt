# - add examples

set(TEST_MODULES_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/examples)

# demos
add_subdirectory(demos/TestEm0/module)
add_subdirectory(demos/water_phantom/module)

# Build custom module and place here
add_subdirectory(/home/angus/GIT/detector_simulation/geantpy/module /home/angus/GIT/detector_simulation/geantpy)
