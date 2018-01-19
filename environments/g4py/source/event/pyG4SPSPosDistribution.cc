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
// $Id: pyG4SPSPosDistribution.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4SPSPosDistribution.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4SPSPosDistribution.hh"

using namespace boost::python;


// ====================================================================
// thin wrappers
// ====================================================================

// ====================================================================
// module definition
// ====================================================================
void export_G4SPSPosDistribution()
{
class_<G4SPSPosDistribution, boost::noncopyable>
    ("G4SPSPosDistribution", "single particle position distribution")
    // constructor
    .def(init<>())
    // ---
    .def("SetPosDisType", &G4SPSPosDistribution::SetPosDisType)
    .def("GetPosDisType", &G4SPSPosDistribution::GetPosDisType)
    .def("SetPosDisShape", &G4SPSPosDistribution::SetPosDisShape)
    .def("GetPosDisShape", &G4SPSPosDistribution::GetPosDisShape)
    .def("SetCentreCoords", &G4SPSPosDistribution::SetCentreCoords)
    .def("GetCentreCoords", &G4SPSPosDistribution::GetCentreCoords)
    .def("SetPosRot1", &G4SPSPosDistribution::SetPosRot1)
    .def("SetPosRot2", &G4SPSPosDistribution::SetPosRot2)
    .def("SetHalfX", &G4SPSPosDistribution::SetHalfX)
    .def("GetHalfX", &G4SPSPosDistribution::GetHalfX)
    .def("SetHalfY", &G4SPSPosDistribution::SetHalfY)
    .def("GetHalfY", &G4SPSPosDistribution::GetHalfY)
    .def("SetHalfZ", &G4SPSPosDistribution::SetHalfZ)
    .def("GetHalfZ", &G4SPSPosDistribution::GetHalfZ)
    .def("SetRadius", &G4SPSPosDistribution::SetRadius)
    .def("GetRadius", &G4SPSPosDistribution::GetRadius)
    .def("SetRadius0", &G4SPSPosDistribution::SetRadius0)
    .def("SetBeamSigmaInR", &G4SPSPosDistribution::SetBeamSigmaInR)
    .def("SetBeamSigmaInX", &G4SPSPosDistribution::SetBeamSigmaInX)
    .def("SetBeamSigmaInY", &G4SPSPosDistribution::SetBeamSigmaInY)
    .def("SetParAlpha", &G4SPSPosDistribution::SetParAlpha)
    .def("SetParTheta", &G4SPSPosDistribution::SetParTheta)
    .def("SetParPhi", &G4SPSPosDistribution::SetParPhi)
    .def("ConfineSourceToVolume", &G4SPSPosDistribution::ConfineSourceToVolume)
    .def("SetBiasRndm", &G4SPSPosDistribution::SetBiasRndm)
    .def("SetVerbosity", &G4SPSPosDistribution::SetVerbosity)
    .def("GenerateOne", &G4SPSPosDistribution::GenerateOne)
    ;
}
