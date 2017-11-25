//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: pyG4Torus.cc 66892 2013-01-17 10:57:59Z gunter $
// ====================================================================
//   pyG4Torus.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4LogicalVolume.hh"
#include "G4VSolid.hh"
#include "CADMesh.hh"
// #include "cadmeshTetrahedralMesh.hh"
// #include "cadmeshPolygonMesh.hh"
#include "G4String.hh"

using namespace boost::python;
using namespace CADMesh;

// ====================================================================
// wrappers
// ====================================================================

// ====================================================================
// module definition
// ====================================================================>
  
namespace pyCADMesh 
{
    #define DEFINE_BASE_MEMBERS(T) \
      class_<T, std::shared_ptr<T>, boost::noncopyable> \
        (#T, #T " class", no_init) \
        .def(init<>())\
        .def(init<G4String>())\
        .def(init<G4String, G4String>())\
        .def("FromPLY", &T::FromPLY)\
        .staticmethod("FromPLY")\
        .def("GetFileName", &T::GetFileName) \
        .def("GetFileType", &T::GetFileType) \
        .def("SetVerbose", &T::SetVerbose) \
        .def("GetVerbose", &T::GetVerbose) \
        .def("SetScale", &T::SetScale) \
        .def("GetScale", &T::GetScale) \
        .def("SetOffset", &T::SetOffset) \
        .def("GetOffset", &T::GetOffset) 
        
    G4TessellatedSolid* (TessellatedMesh::*f1_GetSolid)() = &TessellatedMesh::GetSolid;
    G4TessellatedSolid* (TessellatedMesh::*f2_GetSolid)(G4int) = &TessellatedMesh::GetSolid;
    G4TessellatedSolid* (TessellatedMesh::*f3_GetSolid)(G4String) = &TessellatedMesh::GetSolid;
}

using namespace pyCADMesh;

void export_CADMesh()
{
    DEFINE_BASE_MEMBERS(TessellatedMesh)
    .def("GetSolid", f1_GetSolid, return_internal_reference<>())
    .def("GetSolid", f2_GetSolid, return_internal_reference<>())
    .def("GetSolid", f3_GetSolid, return_internal_reference<>())
    .def("SetReverse", &TessellatedMesh::SetReverse)
    .def("GetReverse", &TessellatedMesh::GetReverse)
    ;
    
    DEFINE_BASE_MEMBERS(TetrahedralMesh)
    .def("GetAssembly", &TetrahedralMesh::GetAssembly, return_internal_reference<>())
    .def("SetMaterial", &TetrahedralMesh::SetMaterial)
    .def("GetMaterial", &TetrahedralMesh::GetMaterial,
        return_internal_reference<>())
    .def("SetQuality", &TetrahedralMesh::SetQuality)
    .def("GetQuality", &TetrahedralMesh::GetQuality)
    ;
    
    class_<G4TessellatedSolid, G4TessellatedSolid*, bases<G4VSolid>, boost::noncopyable>("G4TessellatedSolid", no_init)
    ;
}
