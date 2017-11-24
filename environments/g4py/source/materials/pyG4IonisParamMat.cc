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
// $Id: pyG4IonisParamMat.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4IonisParamMat.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4IonisParamMat.hh"
#include "G4Material.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4IonisParamMat {
}

using namespace pyG4IonisParamMat;

// ====================================================================
// module definition
// ====================================================================
void export_G4IonisParamMat()
{
  class_<G4IonisParamMat, G4IonisParamMat*, boost::noncopyable>
    ("G4IonisParamMat", "ionisation params class", no_init)
        
    .def("GetMeanExcitationEnergy", &G4IonisParamMat::GetMeanExcitationEnergy)
  
    .def("SetMeanExcitationEnergy", &G4IonisParamMat::SetMeanExcitationEnergy)
    .def("FindMeanExcitationEnergy", &G4IonisParamMat::FindMeanExcitationEnergy)
  
    .def("GetLogMeanExcEnergy", &G4IonisParamMat::GetLogMeanExcEnergy)
    //inline    G4double* GetShellCorrectionVector()  const {return fShellCorrectionVector;}; // TODO
    .def("GetTaul", &G4IonisParamMat::GetTaul)
      
    // parameters of the density correction:
    .def("GetPlasmaEnergy", &G4IonisParamMat::GetPlasmaEnergy)
    .def("GetAdjustmentFactor", &G4IonisParamMat::GetAdjustmentFactor)
    .def("GetCdensity", &G4IonisParamMat::GetCdensity)
    .def("GetMdensity", &G4IonisParamMat::GetMdensity)
    .def("GetAdensity", &G4IonisParamMat::GetAdensity)
    .def("GetX0density", &G4IonisParamMat::GetX0density)
    .def("GetX1density", &G4IonisParamMat::GetX1density)
    .def("GetD0density", &G4IonisParamMat::GetD0density)
    
    .def("DensityCorrection", &G4IonisParamMat::DensityCorrection)
  
    // .def("GetDensityEffectData", &G4IonisParamMat::GetDensityEffectData,
	//    return_internal_reference<>()) TODO
  
    // parameters of the energy loss fluctuation model:
    .def("GetF1fluct", &G4IonisParamMat::GetF1fluct)
    .def("GetF2fluct", &G4IonisParamMat::GetF2fluct)
    .def("GetEnergy1fluct", &G4IonisParamMat::GetEnergy1fluct)
    .def("GetLogEnergy1fluct", &G4IonisParamMat::GetLogEnergy1fluct)
    .def("GetEnergy2fluct", &G4IonisParamMat::GetEnergy2fluct)
    .def("GetLogEnergy2fluct", &G4IonisParamMat::GetLogEnergy2fluct)
    .def("GetEnergy0fluct", &G4IonisParamMat::GetEnergy0fluct)
    .def("GetRateionexcfluct", &G4IonisParamMat::GetRateionexcfluct)
  
    // parameters for ion corrections computations
    .def("GetZeffective", &G4IonisParamMat::GetZeffective)
    .def("GetFermiEnergy", &G4IonisParamMat::GetFermiEnergy)
    .def("GetLFactor", &G4IonisParamMat::GetLFactor)
    .def("GetInvA23", &G4IonisParamMat::GetInvA23)
      
    // parameters for Birks attenuation:
    .def("SetBirksConstant", &G4IonisParamMat::SetBirksConstant)
    .def("GetBirksConstant", &G4IonisParamMat::GetBirksConstant)
  
    // parameters for average energy per ion 
    .def("SetMeanEnergyPerIonPair", &G4IonisParamMat::SetMeanEnergyPerIonPair)
    .def("GetMeanEnergyPerIonPair", &G4IonisParamMat::GetMeanEnergyPerIonPair)
        
    ;
}

