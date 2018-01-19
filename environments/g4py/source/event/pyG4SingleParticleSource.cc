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
// $Id: pyG4SingleParticleSource.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4SingleParticleSource.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4SingleParticleSource.hh"
#include "G4Event.hh"

using namespace boost::python;


// ====================================================================
// thin wrappers
// ====================================================================

// ====================================================================
// module definition
// ====================================================================
void export_G4SingleParticleSource()
{
class_<G4SingleParticleSource, bases<G4VPrimaryGenerator>, boost::noncopyable>
    ("G4SingleParticleSource", "general particle source")
    // constructor
    .def(init<>())
    // ---
    .def("GeneratePrimaryVertex", &G4SingleParticleSource::GeneratePrimaryVertex)

    .def("GetPosDist", &G4SingleParticleSource::GetPosDist,
        return_value_policy<reference_existing_object>())
    .def("GetAngDist", &G4SingleParticleSource::GetPosDist,
        return_value_policy<reference_existing_object>())
    .def("GetEneDist", &G4SingleParticleSource::GetEneDist,
    	return_value_policy<reference_existing_object>())
    .def("GetBiasRndm", &G4SingleParticleSource::GetBiasRndm,
    	return_value_policy<reference_existing_object>())
    
    .def("SetVerbosity", &G4SingleParticleSource::SetVerbosity)
    
    .def("SetParticleDefinition", &G4SingleParticleSource::SetParticleDefinition)
    .def("GetParticleDefinition", &G4SingleParticleSource::GetParticleDefinition,
    	 return_value_policy<reference_existing_object>())
    
    .def("SetParticleCharge",     &G4SingleParticleSource::SetParticleCharge)
    
    .def("SetParticlePolarization", &G4SingleParticleSource::SetParticlePolarization)
    .def("GetParticlePolarization", &G4SingleParticleSource::GetParticlePolarization)
    
    .def("SetParticleTime",       &G4SingleParticleSource::SetParticleTime)
    .def("GetParticleTime",       &G4SingleParticleSource::GetParticleTime)
    
    .def("SetNumberOfParticles",  &G4SingleParticleSource::SetNumberOfParticles)
    .def("GetNumberOfParticles",  &G4SingleParticleSource::GetNumberOfParticles)
    
    .def("GetParticlePosition",   &G4SingleParticleSource::GetParticlePosition)
    .def("GetParticleMomentumDirection",
	 &G4SingleParticleSource::GetParticleMomentumDirection)
    .def("GetParticleEnergy",       &G4SingleParticleSource::GetParticleEnergy)
    ;
}
