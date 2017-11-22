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
// $Id: pyG4Material.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4Material.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "pyG4indexing.hh"

#include "G4Version.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4LogicalVolume.hh"
#include "G4SurfaceProperty.hh"

using namespace boost::python;


namespace pyG4LogicalSkinSurface
{

}

using namespace pyG4LogicalSkinSurface;

// ====================================================================
// module definition
// ====================================================================
void export_G4LogicalSkinSurface()
{
    class_<G4LogicalSkinSurfaceTable> ("G4LogicalSkinSurfaceTable")
      .def(vector_indexing_suite<G4LogicalSkinSurfaceTable>())
      ;

    class_<G4LogicalSkinSurface, G4LogicalSkinSurface*, boost::noncopyable>
      ("G4LogicalSkinSurface", "logical skin surface class", no_init)
    .def(init<const G4String&, G4LogicalVolume*,
      G4SurfaceProperty*>())
    // ---
    .def("GetSurface", &G4LogicalSkinSurface::GetSurface,
      return_value_policy<reference_existing_object>())
    .staticmethod("GetSurface")
    
    .def("GetLogicalVolume", &G4LogicalSkinSurface::GetLogicalVolume,
      return_value_policy<reference_existing_object>())
    .def("SetLogicalVolume", &G4LogicalSkinSurface::SetLogicalVolume)

    .def("CleanSurfaceTable", &G4LogicalSkinSurface::CleanSurfaceTable)
    .staticmethod("CleanSurfaceTable")

    .def("GetSurfaceTable", &G4LogicalSkinSurface::GetSurfaceTable,
      return_value_policy<reference_existing_object>())
    .staticmethod("GetSurfaceTable")

    .def("GetNumberOfSkinSurfaces", &G4LogicalSkinSurface::GetNumberOfSkinSurfaces)
    .staticmethod("GetNumberOfSkinSurfaces")

    .def("DumpInfo", &G4LogicalSkinSurface::DumpInfo)
    .staticmethod("DumpInfo")

    .def(self==self)
    .def(self!=self)
    ;
}
