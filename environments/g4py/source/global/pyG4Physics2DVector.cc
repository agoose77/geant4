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
// $Id: pyG4Physics2DVector.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4Physics2DVector.cc
//
//                                         2007 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "pyG4indexing.hh"
#include "G4MaterialPropertiesTable.hh"

#include "G4Physics2DVector.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4Physics2DVector 
{
    tuple f1_Value(const G4Physics2DVector& vec, G4double x, G4double y, size_t lastidx, size_t lastidy)
    {
        G4double value = vec.Value(x, y, lastidx, lastidy);
        return make_tuple(value, lastidx, lastidy);
    }
    G4double (G4Physics2DVector::*f2_Value)(G4double, G4double) const = &G4Physics2DVector::Value;
    
    tuple f1_FindLinearX(const G4Physics2DVector& vec, G4double rand, G4double y, size_t lastidy)
    {
        G4double linear_x = vec.FindLinearX(rand, y, lastidy);
        return make_tuple(linear_x, lastidy);
    }    
    G4double (G4Physics2DVector::*f2_FindLinearX)(G4double, G4double) const = &G4Physics2DVector::FindLinearX;
}

using namespace pyG4Physics2DVector;

// ====================================================================
// module definition
// ====================================================================
void export_G4Physics2DVector()
{

  class_<G4PV2DDataVector>("G4PV2DDataVector", "Double Vector wrapper")
    .def(vector_indexing_suite<G4PV2DDataVector>())
    ;
    
  class_<G4Physics2DVector, boost::noncopyable>("G4Physics2DVector", "general 2-vector", no_init)
    // constructors
    .def(init<>())
    .def(init<size_t, size_t>())
    .def(init<const G4Physics2DVector&>())

    // methods
    .def("Value", f1_Value)
    .def("Value", f2_Value)
    .def("PutX", &G4Physics2DVector::PutX)
    .def("PutY", &G4Physics2DVector::PutY)
    .def("PutValue", &G4Physics2DVector::PutValue)
    
    .def("PutVectors", &G4Physics2DVector::PutVectors)
    .def("ScaleVector", &G4Physics2DVector::ScaleVector)
    .def("FindLinearX", f1_FindLinearX)
    .def("FindLinearX", f2_FindLinearX)
    
    .def("GetX", &G4Physics2DVector::GetX)
    .def("GetY", &G4Physics2DVector::GetY)
    
    .def("GetValue", &G4Physics2DVector::GetValue)
    
    .def("FindBinLocationX", &G4Physics2DVector::FindBinLocationX)
    .def("FindBinLocationY", &G4Physics2DVector::FindBinLocationY)
    
    .def("GetLengthX", &G4Physics2DVector::GetLengthX)
    .def("GetLengthY", &G4Physics2DVector::GetLengthY)
    
    .def("GetType", &G4Physics2DVector::GetType)
    .def("SetBicubicInterpolation", &G4Physics2DVector::SetBicubicInterpolation)
    
    .def("SetVerboseLevel", &G4Physics2DVector::SetVerboseLevel)
    ;
    
    enum_<G4PhysicsVectorType>("G4PhysicsVectorType")
      .value("T_G4PhysicsVector,", T_G4PhysicsVector)
      .value("T_G4PhysicsLinearVector,", T_G4PhysicsLinearVector)
      .value("T_G4PhysicsLogVector,", T_G4PhysicsLogVector)
      .value("T_G4PhysicsLnVector,", T_G4PhysicsLnVector)
      .value("T_G4PhysicsFreeVector,", T_G4PhysicsFreeVector)
      .value("T_G4PhysicsOrderedFreeVector,", T_G4PhysicsOrderedFreeVector)
      .value("T_G4LPhysicsFreeVector", T_G4LPhysicsFreeVector)
    ;

}


