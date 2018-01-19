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
// $Id: pyG4GeneralParticleSource.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4GeneralParticleSource.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4GeneralParticleSource.hh"
#include "G4Event.hh"
#include "G4ParticleTable.hh"

using namespace boost::python;


// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4GeneralParticleSource {

////////////////////////////////////////////////////////////////////
void SetParticleByName(G4GeneralParticleSource* gun, const std::string& pname)
////////////////////////////////////////////////////////////////////
{
  G4ParticleTable* particleTable= G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* pd= particleTable-> FindParticle(pname);
  if (pd != 0) {
    gun-> SetParticleDefinition(pd);
  } else {
    G4cout << "*** \"" << pname << "\" is not registered "
	   << "in available particle list" << G4endl;
  }
}

/////////////////////////////////////////////////
std::string GetParticleByName(G4GeneralParticleSource* gun)
/////////////////////////////////////////////////
{
  const G4ParticleDefinition* pd= gun-> GetParticleDefinition();
  return (pd-> GetParticleName()).c_str();
}

}

using namespace pyG4GeneralParticleSource;

// ====================================================================
// module definition
// ====================================================================
void export_G4GeneralParticleSource()
{
class_<G4GeneralParticleSource, bases<G4VPrimaryGenerator>, boost::noncopyable>
    ("G4GeneralParticleSource", "general particle source")
    // constructor
    .def(init<>())
    // ---
    .def("GeneratePrimaryVertex", &G4GeneralParticleSource::GeneratePrimaryVertex)
    
    .def("GetNumberofSource", &G4GeneralParticleSource::GetNumberofSource)
    .def("ListSource", &G4GeneralParticleSource::ListSource)
    
    .def("SetCurrentSourceto", &G4GeneralParticleSource::SetCurrentSourceto)
    .def("SetCurrentSourceIntensity", &G4GeneralParticleSource::SetCurrentSourceIntensity)
    
    .def("GetCurrentSource", &G4GeneralParticleSource::GetCurrentSource,
    	 return_value_policy<reference_existing_object>())
    .def("GetCurrentSourceIndex", &G4GeneralParticleSource::GetCurrentSourceIndex)
    .def("GetCurrentSourceIntensity", &G4GeneralParticleSource::GetCurrentSourceIntensity)
    
    .def("ClearAll", &G4GeneralParticleSource::ClearAll)
    
    .def("AddaSource", &G4GeneralParticleSource::AddaSource)
    .def("DeleteaSource", &G4GeneralParticleSource::DeleteaSource)
    
    .def("SetVerbosity", &G4GeneralParticleSource::SetVerbosity)
    .def("SetMultipleVertex", &G4GeneralParticleSource::SetMultipleVertex)
            
    .def("SetFlatSampling", &G4GeneralParticleSource::SetFlatSampling)
    
    .def("SetParticleDefinition", &G4GeneralParticleSource::SetParticleDefinition)
    .def("GetParticleDefinition", &G4GeneralParticleSource::GetParticleDefinition,
    	 return_value_policy<reference_existing_object>())
    
    .def("SetParticleCharge",     &G4GeneralParticleSource::SetParticleCharge)
    
    .def("SetParticleByName",     SetParticleByName)
    .def("GetParticleByName",     GetParticleByName)
    
    .def("SetParticlePolarization", &G4GeneralParticleSource::SetParticlePolarization)
    .def("GetParticlePolarization", &G4GeneralParticleSource::GetParticlePolarization)
    
    .def("SetParticleTime",       &G4GeneralParticleSource::SetParticleTime)
    .def("GetParticleTime",       &G4GeneralParticleSource::GetParticleTime)
    
    .def("SetNumberOfParticles",  &G4GeneralParticleSource::SetNumberOfParticles)
    .def("GetNumberOfParticles",  &G4GeneralParticleSource::GetNumberOfParticles)
    
    .def("GetParticlePosition",   &G4GeneralParticleSource::GetParticlePosition)
    .def("GetParticleMomentumDirection",
	 &G4GeneralParticleSource::GetParticleMomentumDirection)
    .def("GetParticleEnergy",       &G4GeneralParticleSource::GetParticleEnergy)
    ;
}
