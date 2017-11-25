# - build library

find_package(cadmesh)

if(NOT DEFINED cadmesh_FOUND)
    error("Couldn't find cadmesh")
else()
    message("FOUND CADMESH" )
endif()

# library
include_directories (
  ${cadmesh_INCLUDE_DIRS}
)
set(_TARGET pyCADMesh)
add_library (
  ${_TARGET} SHARED
  pyCADMesh.cc
  pymodCADMesh.cc
)

set_target_properties(${_TARGET} PROPERTIES PREFIX "")
set_target_properties(${_TARGET} PROPERTIES OUTPUT_NAME "CADMesh")
set_target_properties(${_TARGET} PROPERTIES SUFFIX ".so")
set_target_properties(${_TARGET}
                      PROPERTIES INSTALL_RPATH
                      ${GEANT4_LIBRARY_DIR}
                      BUILD_WITH_INSTALL_RPATH TRUE)

target_link_libraries (${_TARGET}
                      ${GEANT4_LIBRARIES_WITH_VIS} 
                      boost_python
                      ${cadmesh_LIBRARIES}
                      ${PYTHON_LIBRARIES})
# install
install(TARGETS ${_TARGET} LIBRARY DESTINATION ${G4MODULES_INSTALL_DIR})
