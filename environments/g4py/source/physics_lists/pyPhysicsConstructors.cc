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
// $Id: pyPhysicsConstructors.cc 76884 2017-11-18 12:54:03Z agoose77 $
// ====================================================================
//   pyPhysicsConstructors.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4VPhysicsConstructor.hh"

// EM physics
#include "G4EmPenelopePhysics.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmLowEPPhysics.hh"
#include "G4OpticalPhysics.hh"

// Hadron
#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4HadronPhysicsFTFP_BERT_HP.hh"
#include "G4HadronPhysicsFTFP_BERT_TRV.hh"
#include "G4HadronPhysicsFTF_BIC.hh"

#include "G4HadronPhysicsQGSP_BERT.hh"
#include "G4HadronPhysicsQGSP_BERT_HP.hh"
#include "G4HadronPhysicsQGSP_BIC.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4HadronPhysicsQGSP_FTFP_BERT.hh"

#include "G4HadronPhysicsShielding.hh"

// Decays
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"


// macro for adding physics constructors
#define ADD_PHYSICS_CONSTRUCTOR(plname) \
  class_<plname, plname*, bases<G4VPhysicsConstructor>, boost::noncopyable> \
    (#plname, #plname " physics constructor") \
    ; \
  AddPhysicsConstructor(#plname);

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyPhysicsConstructors {
    
      static std::vector<std::string> constructorList;

    void AddPhysicsConstructor(const G4String& constructor_name) {
      constructorList.push_back(constructor_name);
    }

    void ListPhysicsConstructors() {
      for (G4int i=0; i< constructorList.size(); i++) {
        G4cout << constructorList[i] << G4endl;
      }
    }
}

using namespace pyPhysicsConstructors;

// ====================================================================
// module definition
// ====================================================================
void export_PhysicsConstructors()
{
    def("ListPhysicsConstructors", ListPhysicsConstructors);

    // Hadrons
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsFTFP_BERT)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsFTFP_BERT_HP)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsFTFP_BERT_TRV)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsFTF_BIC)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsQGSP_BERT)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsQGSP_BERT_HP)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsQGSP_BIC)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsQGSP_BIC_HP)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsQGSP_FTFP_BERT)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsShielding)
    ADD_PHYSICS_CONSTRUCTOR(G4HadronPhysicsFTFP_BERT)
    
    // Decays
    ADD_PHYSICS_CONSTRUCTOR(G4DecayPhysics)
    ADD_PHYSICS_CONSTRUCTOR(G4RadioactiveDecayPhysics)
    
    // EM
    ADD_PHYSICS_CONSTRUCTOR(G4EmPenelopePhysics)
    ADD_PHYSICS_CONSTRUCTOR(G4EmLivermorePhysics)
    ADD_PHYSICS_CONSTRUCTOR(G4EmStandardPhysics)
    ADD_PHYSICS_CONSTRUCTOR(G4EmStandardPhysics_option4)
    ADD_PHYSICS_CONSTRUCTOR(G4EmLowEPPhysics)
    
    // Optical
    class_<G4OpticalPhysics, G4OpticalPhysics*, bases<G4VPhysicsConstructor>, boost::noncopyable> ("G4OpticalPhysics", "G4OpticalPhysics physics constructor")
        .def("Configure", &G4OpticalPhysics::Configure)
      
        .def("SetMaxNumPhotonsPerStep", &G4OpticalPhysics::SetMaxNumPhotonsPerStep)
        .def("SetMaxBetaChangePerStep", &G4OpticalPhysics::SetMaxBetaChangePerStep)
        .def("SetScintillationYieldFactor", &G4OpticalPhysics::SetScintillationYieldFactor)
        .def("SetScintillationExcitationRatio", &G4OpticalPhysics::SetScintillationExcitationRatio)

        .def("SetWLSTimeProfile", &G4OpticalPhysics::SetWLSTimeProfile)
        .def("SetScintillationByParticleType", &G4OpticalPhysics::SetScintillationByParticleType)
        .def("SetScintillationTrackInfo", &G4OpticalPhysics::SetScintillationTrackInfo)

        .def("SetTrackSecondariesFirst", &G4OpticalPhysics::SetTrackSecondariesFirst)
        .def("SetFiniteRiseTime", &G4OpticalPhysics::SetFiniteRiseTime)

        .def("SetCerenkovStackPhotons", &G4OpticalPhysics::SetCerenkovStackPhotons)
        .def("SetScintillationStackPhotons", &G4OpticalPhysics::SetScintillationStackPhotons)

        .def("SetInvokeSD", &G4OpticalPhysics::SetInvokeSD)
      ; 
    AddPhysicsConstructor("G4OpticalPhysics");
    
    enum_<G4OpticalProcessIndex>("G4OpticalProcessIndex")
        .value("kCerenkov", kCerenkov)      ///< Cerenkov process index
        .value("kScintillation", kScintillation) ///< Scintillation process index
        .value("kAbsorption", kAbsorption)    ///< Absorption process index
        .value("kRayleigh", kRayleigh)      ///< Rayleigh scattering process index
        .value("kMieHG", kMieHG)         ///< Mie scattering process index
        .value("kBoundary", kBoundary)      ///< Boundary process index
        .value("kWLS", kWLS)           ///< Wave Length Shifting process index
        .value("kNoProcess", kNoProcess)              ///< Number of processes, no selected process
      ;
    
    // sort PL vector
    std::sort(constructorList.begin(), constructorList.end());
}

