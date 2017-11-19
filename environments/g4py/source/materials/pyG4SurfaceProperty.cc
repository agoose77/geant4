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
// $Id: pyG4SurfaceProperty.cc 76884 2017-11-18 20:55:03Z agoose77 $
// ====================================================================
//   pyG4SurfaceProperty.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4SurfaceProperty.hh"
#include "pyG4indexing.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4SurfaceProperty {
    // Wrappers to overcome return /arg of reference type
    // G4SurfaceType f_GetType(G4SurfaceProperty& prop)
    // {
    //     return prop.GetType();
    // }
    // void f_SetType(G4SurfaceProperty& prop, G4SurfaceType type)
    // {
    //     prop.SetType(type);
    // }

}

using namespace pyG4SurfaceProperty;

// ====================================================================
// module definition
// ====================================================================
void export_G4SurfaceProperty()
{

  class_<G4SurfacePropertyTable>("G4SurfacePropertyTable", "Surface Property Table")
    .def(vector_indexing_suite<G4SurfacePropertyTable>())
    ;
    
  class_<G4SurfaceProperty, G4SurfaceProperty*, boost::noncopyable>
    ("G4SurfaceProperty", "surface property class", no_init)
    .def(init<>())
    .def(init<const G4String&, G4SurfaceType>())
    // 
    .def("GetName", &G4SurfaceProperty::GetName, 
         return_value_policy<reference_existing_object>())
    .def("SetName", &G4SurfaceProperty::SetName)
    .def("GetType", &G4SurfaceProperty::GetType, 
         return_value_policy<copy_const_reference>())
    .def("SetType", &G4SurfaceProperty::SetType)
    
    .def("CleanSurfacePropertyTable", &G4SurfaceProperty::CleanSurfacePropertyTable,
         return_value_policy<reference_existing_object>())
    .staticmethod("CleanSurfacePropertyTable")
    
    .def("GetSurfacePropertyTable", &G4SurfaceProperty::GetSurfacePropertyTable,
         return_value_policy<reference_existing_object>())
    .staticmethod("GetSurfacePropertyTable")
    
    .def("GetNumberOfSurfaceProperties", &G4SurfaceProperty::GetNumberOfSurfaceProperties)
    .staticmethod("GetNumberOfSurfaceProperties")
    
    .def("DumpTableInfo", &G4SurfaceProperty::DumpTableInfo)
    .staticmethod("DumpTableInfo")
    ;

    enum_<G4SurfaceType>("G4SurfaceType")
       .value("dielectric_metal", dielectric_metal)            // dielectric-metal interface
       .value("dielectric_dielectric", dielectric_dielectric)       // dielectric-dielectric interface
       .value("dielectric_LUT", dielectric_LUT)              // dielectric-Look-Up-Table interface
       .value("dielectric_dichroic", dielectric_dichroic)         // dichroic filter interface
       .value("firsov", firsov)                      // for Firsov Process
       .value("x_ray", x_ray)                      // for x-ray mirror process
       ;
}

