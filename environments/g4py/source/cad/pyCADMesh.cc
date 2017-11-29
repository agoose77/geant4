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
#include "G4String.hh"

using namespace boost::python;

// ====================================================================
// wrappers
// ====================================================================

// ====================================================================
// module definition
// ====================================================================>
  
namespace pyCADMesh 
{   
    typedef CADMesh T;
    G4VSolid* (T::*f1_TessellatedMesh)() = &T::TessellatedMesh;
    G4VSolid* (T::*f2_TessellatedMesh)(G4int) = &T::TessellatedMesh;
    G4VSolid* (T::*f3_TessellatedMesh)(G4String) = &T::TessellatedMesh;    
}

using namespace pyCADMesh;

void export_CADMesh()
{
  class_<T, boost::noncopyable> 
    ("CADMesh", "CADMesh class", no_init) 
    .def(init<char*>())
    .def(init<char*, char*>())
        
    .def("GetFileName", &T::GetFileName) 
    .def("GetFileType", &T::GetFileType) 
    .def("SetVerbose", &T::SetVerbose) 
    .def("GetVerbose", &T::GetVerbose) 
    .def("SetScale", &T::SetScale) 
    .def("GetScale", &T::GetScale) 
    .def("SetOffset", &T::SetOffset) 
    .def("GetOffset", &T::GetOffset) 
    .def("SetReverse", &T::SetReverse)
    .def("GetReverse", &T::GetReverse)
    .def("SetQuality", &T::SetQuality) 
    .def("GetQuality", &T::GetQuality) 
    
    // TessellatedMesh
    .def("TessellatedMesh", f1_TessellatedMesh, return_internal_reference<>())
    .def("TessellatedMesh", f2_TessellatedMesh, return_internal_reference<>())
    .def("TessellatedMesh", f3_TessellatedMesh, return_internal_reference<>())
    .def("GetSolid", &T::GetSolid, return_internal_reference<>())
    
    // TetrahedralMesh 
    .def("GetAssembly", &T::GetAssembly, return_internal_reference<>())
    .def("TetrahedralMesh", &T::TetrahedralMesh, return_internal_reference<>())
    .def("SetMaterial", &T::SetMaterial) 
    .def("GetMaterial", &T::GetMaterial, return_internal_reference<>()) 
    ;
    
    class_<G4TessellatedSolid, G4TessellatedSolid*, bases<G4VSolid>, boost::noncopyable>("G4TessellatedSolid", no_init)
    ;
}
