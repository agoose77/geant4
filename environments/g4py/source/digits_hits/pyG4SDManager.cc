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
// $Id: pyG4SDManager.cc 86749 2014-11-17 15:03:05Z gcosmo $
// ====================================================================
//   pyG4SDManager.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4SDManager.hh"
#include "G4Event.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4SDManager {

}

using namespace pyG4SDManager;

// ====================================================================
// module definition
// ====================================================================
void export_G4SDManager()
{
  class_<G4SDManager, boost::noncopyable>
    ("G4SDManager", "sensitive detector manager class", no_init)
    // ---
    .def("GetSDMpointer", &G4SDManager::GetSDMpointer,
        "Get an instance of G4SDManager",
        return_value_policy<reference_existing_object>())
    .staticmethod("GetSDMpointer")
    .def("GetSDMpointerIfExist", &G4SDManager::GetSDMpointerIfExist,
        "Get an instance of G4SDManager if it exists",
        return_value_policy<reference_existing_object>())
    .staticmethod("GetSDMpointerIfExist")
    // ---
    .def("SetVerboseLevel", &G4SDManager::SetVerboseLevel)
    // ---
    .def("AddNewDetector", &G4SDManager::AddNewDetector)
    .def("Activate", &G4SDManager::Activate)
    .def("FindSensitiveDetector", &G4SDManager::FindSensitiveDetector,
        return_value_policy<reference_existing_object>())
        
    .def("ListTree", &G4SDManager::ListTree)
    ;

    // reduced functionality...
    // void SetPrimaryTransformer(G4PrimaryTransformer* pt)
    // void SetNumberOfAdditionalWaitingStacks(G4int iAdd)
    // void CutOffHasBeenModified()
    // void SetGeometryToBeOptimized(G4bool vl)
    // const G4Event* GetPreviousEvent(G4int i) const
    // void SetNumberOfEventsToBeStored(G4int val)
    // void SetDCtable(G4DCtable* DCtbl)

}
