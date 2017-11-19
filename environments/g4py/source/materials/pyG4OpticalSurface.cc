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
// $Id: pyG4OpticalSurface.cc 76884 2017-11-18 20:55:03Z agoose77 $
// ====================================================================
//   pyG4OpticalSurface.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4OpticalSurface.hh"
#include "G4MaterialPropertiesTable.hh"
#include "pyG4indexing.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4OpticalSurface {
    
}

using namespace pyG4OpticalSurface;

// ====================================================================
// module definition
// ====================================================================
void export_G4OpticalSurface()
{
  class_<G4OpticalSurface, G4OpticalSurface*, bases<G4SurfaceProperty>, boost::noncopyable>
    ("G4OpticalSurface", "optical surface class", no_init)
    .def(init<const G4OpticalSurface&>()) // Copy constructor
    .def(init<const G4String&,
			 G4OpticalSurfaceModel,
			 G4OpticalSurfaceFinish,
			 G4SurfaceType,
			 G4double>())
             
    .def("SetType", &G4OpticalSurface::SetType)
    
    .def("GetModel", &G4OpticalSurface::GetModel)
    .def("SetModel", &G4OpticalSurface::SetModel)
    
    .def("GetFinish", &G4OpticalSurface::GetFinish)
    .def("SetFinish", &G4OpticalSurface::SetFinish)
    
    .def("GetSigmaAlpha", &G4OpticalSurface::GetSigmaAlpha)
    .def("SetSigmaAlpha", &G4OpticalSurface::SetSigmaAlpha)
    
    .def("GetPolish", &G4OpticalSurface::GetPolish)
    .def("SetPolish", &G4OpticalSurface::SetPolish)

    .def("GetMaterialPropertiesTable", &G4OpticalSurface::GetMaterialPropertiesTable,
        return_value_policy<reference_existing_object>())
    .def("SetMaterialPropertiesTable", &G4OpticalSurface::SetMaterialPropertiesTable)
    
    .def("DumpInfo", &G4OpticalSurface::DumpInfo)
    .def("GetAngularDistributionValue", &G4OpticalSurface::GetAngularDistributionValue)
    .def("GetThetaIndexMax", &G4OpticalSurface::GetThetaIndexMax)
    .def("GetPhiIndexMax", &G4OpticalSurface::GetPhiIndexMax)
    .def("GetDichroicVector", &G4OpticalSurface::GetDichroicVector,
	 return_internal_reference<>())
        
    .def(self == self)
    .def(self != self)
    ;
    
    enum_<G4OpticalSurfaceFinish>("G4OpticalSurfaceFinish")
       .value("polished", polished)                    // smooth perfectly polished surface
       .value("polishedfrontpainted", polishedfrontpainted)        // smooth top-layer (front) paint
       .value("polishedbackpainted", polishedbackpainted)         // same is 'polished' but with a back-paint

       .value("ground", ground)                      // rough surface
       .value("groundfrontpainted", groundfrontpainted)          // rough top-layer (front) paint
       .value("groundbackpainted", groundbackpainted)           // same as 'ground' but with a back-paint

       .value("polishedlumirrorair", polishedlumirrorair)         // mechanically polished surface, with lumirror
       .value("polishedlumirrorglue", polishedlumirrorglue)        // mechanically polished surface, with lumirror & meltmount
       .value("polishedair", polishedair)                 // mechanically polished surface
       .value("polishedteflonair", polishedteflonair)           // mechanically polished surface, with teflon
       .value("polishedtioair", polishedtioair)              // mechanically polished surface, with tio paint
       .value("polishedtyvekair", polishedtyvekair)            // mechanically polished surface, with tyvek
       .value("polishedvm2000air", polishedvm2000air)           // mechanically polished surface, with esr film
       .value("polishedvm2000glue", polishedvm2000glue)          // mechanically polished surface, with esr film & meltmount

       .value("etchedlumirrorair", etchedlumirrorair)           // chemically etched surface, with lumirror
       .value("etchedlumirrorglue", etchedlumirrorglue)          // chemically etched surface, with lumirror & meltmount
       .value("etchedair", etchedair)                   // chemically etched surface
       .value("etchedteflonair", etchedteflonair)             // chemically etched surface, with teflon
       .value("etchedtioair", etchedtioair)                // chemically etched surface, with tio paint
       .value("etchedtyvekair", etchedtyvekair)              // chemically etched surface, with tyvek
       .value("etchedvm2000air", etchedvm2000air)             // chemically etched surface, with esr film
       .value("etchedvm2000glue", etchedvm2000glue)            // chemically etched surface, with esr film & meltmount

       .value("groundlumirrorair", groundlumirrorair)           // rough-cut surface, with lumirror
       .value("groundlumirrorglue", groundlumirrorglue)          // rough-cut surface, with lumirror & meltmount
       .value("groundair", groundair)                   // rough-cut surface
       .value("groundteflonair", groundteflonair)             // rough-cut surface, with teflon
       .value("groundtioair", groundtioair)                // rough-cut surface, with tio paint
       .value("groundtyvekair", groundtyvekair)              // rough-cut surface, with tyvek
       .value("groundvm2000air", groundvm2000air)             // rough-cut surface, with esr film
       .value("groundvm2000glue",groundvm2000glue)             // rough-cut surface, with esr film & meltmount
    ;
    
    enum_<G4OpticalSurfaceModel>("G4OpticalSurfaceModel")
       .value("glisur", glisur)                      // original GEANT3 model
       .value("unified", unified)                     // UNIFIED model
       .value("LUT", LUT)                         // Look-Up-Table model
       .value("dichroic", dichroic)                     // dichroic filter
    ;
}

