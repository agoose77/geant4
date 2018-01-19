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
// $Id: pyG4SPSAngDistribution.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4SPSAngDistribution.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4SPSAngDistribution.hh"

using namespace boost::python;


// ====================================================================
// thin wrappers
// ====================================================================

// ====================================================================
// module definition
// ====================================================================
void export_G4SPSAngDistribution()
{
class_<G4SPSAngDistribution, boost::noncopyable>
    ("G4SPSAngDistribution", "single particle angular distribution")
    // constructor
    .def(init<>())
    // ---
    .def("SetAngDistType", &G4SPSAngDistribution::SetAngDistType)
    .def("DefineAngRefAxes", &G4SPSAngDistribution::DefineAngRefAxes)
    .def("SetMinTheta", &G4SPSAngDistribution::SetMinTheta)
    .def("SetMinPhi", &G4SPSAngDistribution::SetMinPhi)
    .def("SetMaxTheta", &G4SPSAngDistribution::SetMaxTheta)
    .def("SetMaxPhi", &G4SPSAngDistribution::SetMaxPhi)
    .def("SetBeamSigmaInAngR", &G4SPSAngDistribution::SetBeamSigmaInAngR)
    .def("SetBeamSigmaInAngX", &G4SPSAngDistribution::SetBeamSigmaInAngX)
    .def("SetBeamSigmaInAngY", &G4SPSAngDistribution::SetBeamSigmaInAngY)
    .def("UserDefAngTheta", &G4SPSAngDistribution::UserDefAngTheta)
    .def("UserDefAngPhi", &G4SPSAngDistribution::UserDefAngPhi)
    .def("SetFocusPoint", &G4SPSAngDistribution::SetFocusPoint)
    .def("SetParticleMomentumDirection", &G4SPSAngDistribution::SetParticleMomentumDirection)
    .def("SetUseUserAngAxis", &G4SPSAngDistribution::SetUseUserAngAxis)
    .def("SetUserWRTSurface", &G4SPSAngDistribution::SetUserWRTSurface)
    .def("SetPosDistribution", &G4SPSAngDistribution::SetPosDistribution)
    .def("SetBiasRndm", &G4SPSAngDistribution::SetBiasRndm)
    .def("ReSetHist", &G4SPSAngDistribution::ReSetHist)
    .def("SetVerbosity", &G4SPSAngDistribution::SetVerbosity)
    .def("GetDistType", &G4SPSAngDistribution::GetDistType)
    .def("GetMinTheta", &G4SPSAngDistribution::GetMinTheta)
    .def("GetMaxTheta", &G4SPSAngDistribution::GetMaxTheta)
    .def("GetMinPhi", &G4SPSAngDistribution::GetMinPhi)
    .def("GetMaxPhi", &G4SPSAngDistribution::GetMaxPhi)
    .def("GenerateOne", &G4SPSAngDistribution::GenerateOne)
    ;
}
