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
// $Id: pyG4VPrimaryGenerator.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4VPrimaryGenerator.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4VPrimaryGenerator.hh"
#include "G4Event.hh"

using namespace boost::python;


namespace pyG4VPrimaryGenerator{
    class CB_G4VPrimaryGenerator: 
    public G4VPrimaryGenerator,
    public wrapper<G4VPrimaryGenerator>
    {
    public:
          CB_G4VPrimaryGenerator() : G4VPrimaryGenerator() { }
          ~CB_G4VPrimaryGenerator() { }
          void GeneratePrimaryVertex(G4Event* event) {
              get_override("GeneratePrimaryVertex")(&event);
      }
  };
}
    
using namespace pyG4VPrimaryGenerator;

// ====================================================================
// module definition
// ====================================================================
void export_G4VPrimaryGenerator()
{
class_<CB_G4VPrimaryGenerator, CB_G4VPrimaryGenerator*, boost::noncopyable>
    ("G4VPrimaryGenerator", "base class particle source", no_init)
    // ---
    .def("GeneratePrimaryVertex", pure_virtual(&CB_G4VPrimaryGenerator::GeneratePrimaryVertex))
    .def("SetParticlePosition",   &G4VPrimaryGenerator::SetParticlePosition)
    .def("GetParticlePosition",   &G4VPrimaryGenerator::GetParticlePosition)
    .def("SetParticleTime",       &G4VPrimaryGenerator::SetParticleTime)
    .def("GetParticleTime",       &G4VPrimaryGenerator::GetParticleTime)
    ;
}
