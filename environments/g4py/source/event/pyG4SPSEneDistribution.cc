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
// $Id: pyG4SPSEneDistribution.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4SPSEneDistribution.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4SPSEneDistribution.hh"

using namespace boost::python;


// ====================================================================
// thin wrappers
// ====================================================================

// ====================================================================
// module definition
// ====================================================================
void export_G4SPSEneDistribution()
{
class_<G4SPSEneDistribution, boost::noncopyable>
    ("G4SPSEneDistribution", "single particle energy distribution")
    // constructor
    .def(init<>())
    // ---
    .def("SetEnergyDisType", &G4SPSEneDistribution::SetEnergyDisType)
    .def("GetEnergyDisType", &G4SPSEneDistribution::GetEnergyDisType)
    .def("SetEmin", &G4SPSEneDistribution::SetEmin)
    .def("GetEmin", &G4SPSEneDistribution::GetEmin)
    .def("GetArbEmin", &G4SPSEneDistribution::GetArbEmin)
    .def("SetEmax", &G4SPSEneDistribution::SetEmax)
    .def("GetEmax", &G4SPSEneDistribution::GetEmax)
    .def("GetArbEmax", &G4SPSEneDistribution::GetArbEmax)
    .def("SetMonoEnergy", &G4SPSEneDistribution::SetMonoEnergy)
    .def("SetAlpha", &G4SPSEneDistribution::SetAlpha)
    .def("SetBiasAlpha", &G4SPSEneDistribution::SetBiasAlpha)
    .def("SetTemp", &G4SPSEneDistribution::SetTemp)
    .def("SetBeamSigmaInE", &G4SPSEneDistribution::SetBeamSigmaInE)
    .def("SetEzero", &G4SPSEneDistribution::SetEzero)
    .def("SetGradient", &G4SPSEneDistribution::SetGradient)
    .def("SetInterCept", &G4SPSEneDistribution::SetInterCept)
    .def("UserEnergyHisto", &G4SPSEneDistribution::UserEnergyHisto)
    .def("ArbEnergyHisto", &G4SPSEneDistribution::ArbEnergyHisto)
    .def("ArbEnergyHistoFile", &G4SPSEneDistribution::ArbEnergyHistoFile)
    .def("EpnEnergyHisto", &G4SPSEneDistribution::EpnEnergyHisto)
    .def("InputEnergySpectra", &G4SPSEneDistribution::InputEnergySpectra)
    .def("InputDifferentialSpectra", &G4SPSEneDistribution::InputDifferentialSpectra)
    .def("ArbInterpolate", &G4SPSEneDistribution::ArbInterpolate)
    .def("GetIntType", &G4SPSEneDistribution::GetIntType)
    .def("Calculate", &G4SPSEneDistribution::Calculate)
    .def("SetBiasRndm", &G4SPSEneDistribution::SetBiasRndm)
    .def("ReSetHist", &G4SPSEneDistribution::ReSetHist)
    .def("SetVerbosity", &G4SPSEneDistribution::SetVerbosity)
    .def("GetWeight", &G4SPSEneDistribution::GetWeight)
    .def("GetMonoEnergy", &G4SPSEneDistribution::GetMonoEnergy)
    .def("GetSE", &G4SPSEneDistribution::GetSE)
    .def("Getalpha", &G4SPSEneDistribution::Getalpha)
    .def("GetEzero", &G4SPSEneDistribution::GetEzero)
    .def("GetTemp", &G4SPSEneDistribution::GetTemp)
    .def("Getgrad", &G4SPSEneDistribution::Getgrad)
    .def("Getcept", &G4SPSEneDistribution::Getcept)
    .def("GetUserDefinedEnergyHisto", &G4SPSEneDistribution::GetUserDefinedEnergyHisto)
    .def("GetArbEnergyHisto", &G4SPSEneDistribution::GetArbEnergyHisto)
    .def("GenerateOne", &G4SPSEneDistribution::GenerateOne)
    .def("GetProbability", &G4SPSEneDistribution::GetProbability)
    ;
}
