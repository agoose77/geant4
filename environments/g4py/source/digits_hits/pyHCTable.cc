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
// $Id: pyG4HCtable.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4HCtable.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4HCtable.hh"
#include "G4VSensitiveDetector.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4HCtable {
    G4int (G4HCtable::*f1_GetCollectionID)(G4String) const = &G4HCtable::GetCollectionID;
    G4int (G4HCtable::*f2_GetCollectionID)(G4VSensitiveDetector*) const = &G4HCtable::GetCollectionID;
}

using namespace pyG4HCtable;

// ====================================================================
// module definition
// ====================================================================
void export_G4HCtable()
{
    class_<G4HCtable, G4HCtable*, boost::noncopyable>("G4HCtable", "G4HCtable class", no_init)
                    // ---
            .def("GetCollectionID", f1_GetCollectionID)
            .def("GetCollectionID", f2_GetCollectionID)
            .def("entries",               &G4HCtable::entries)
            .def("GetSDname",         &G4HCtable::GetSDname)
            .def("GetHCname",         &G4HCtable::GetHCname)
            ;

}
