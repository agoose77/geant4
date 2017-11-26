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
// $Id: pyG4VisExtent.cc 101892 2016-12-07 08:07:30Z gcosmo $
// ====================================================================
//   pyG4VisExtent.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4AttDef.hh"
#include "G4VisExtent.hh"
#include "G4Point3D.hh"
#include "pyG4indexing.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4VisExtent {

}

using namespace pyG4VisExtent;

// ====================================================================
// module definition
// ====================================================================
void export_G4VisExtent()
{
    class_<G4VisExtent, G4VisExtent*, boost::noncopyable> ("G4VisExtent", "visualization extents", no_init)
    // constructors
    .def(init<G4double, G4double, G4double, G4double, G4double, G4double>())
    .def(init<const G4Point3D&, G4double>())
    // ---    
    .def("GetXmin",           &G4VisExtent::GetXmin)
    .def("GetXmax",           &G4VisExtent::GetXmax)
    .def("GetYmin",           &G4VisExtent::GetYmin)
    .def("GetYmax",           &G4VisExtent::GetYmax)
    .def("GetZmin",           &G4VisExtent::GetZmin)
    .def("GetZmax",           &G4VisExtent::GetZmax)
    
    .def("SetXmin",           &G4VisExtent::SetXmin)
    .def("SetXmax",           &G4VisExtent::SetXmax)
    .def("SetYmin",           &G4VisExtent::SetYmin)
    .def("SetYmax",           &G4VisExtent::SetYmax)
    .def("SetZmin",           &G4VisExtent::SetZmin)
    .def("SetZmax",           &G4VisExtent::SetZmax)
    // operators
    .def(self != self)
    .def(self_ns::str(self))
    ;

}
