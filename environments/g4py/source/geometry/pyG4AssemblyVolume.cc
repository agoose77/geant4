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
// $Id: pyG4AssemblyVolume.cc 94509 2015-11-20 10:14:44Z gcosmo $
// ====================================================================
//   pyG4AssemblyVolume.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Version.hh"
#include "G4AssemblyVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4VSolid.hh"
#include "pyG4indexing.hh"

using namespace boost::python;

// ====================================================================
// thin wrappers
// ====================================================================
namespace pyG4AssemblyVolume {
    void (G4AssemblyVolume::*f1_AddPlacedVolume)(G4LogicalVolume*, G4Transform3D&) = &G4AssemblyVolume::AddPlacedVolume;
    void (G4AssemblyVolume::*f2_AddPlacedVolume)(G4LogicalVolume*, G4ThreeVector&, G4RotationMatrix*) = &G4AssemblyVolume::AddPlacedVolume;
    
    void (G4AssemblyVolume::*f1_AddPlacedAssembly)(G4AssemblyVolume*, G4Transform3D&) = &G4AssemblyVolume::AddPlacedAssembly;
    void (G4AssemblyVolume::*f2_AddPlacedAssembly)(G4AssemblyVolume*, G4ThreeVector&, G4RotationMatrix*) = &G4AssemblyVolume::AddPlacedAssembly;
    
    void (G4AssemblyVolume::*f1_MakeImprint)(G4LogicalVolume*, G4ThreeVector&, G4RotationMatrix*, G4int, G4bool) = &G4AssemblyVolume::MakeImprint;
    void (G4AssemblyVolume::*f2_MakeImprint)(G4LogicalVolume*, G4Transform3D&, G4int, G4bool) = &G4AssemblyVolume::MakeImprint;
    
    std::vector<G4VPhysicalVolume*>::iterator f_GetVolumesIterator_End(G4AssemblyVolume& ass)
    {
        std::vector<G4VPhysicalVolume*>::iterator it = ass.GetVolumesIterator();
        for (int i=0; i < ass.TotalImprintedVolumes(); i++)
        {
            it++;
        }
        return it;
    }
}

using namespace pyG4AssemblyVolume;

// ====================================================================
// module definition
// ====================================================================
void export_G4AssemblyVolume()
{
    
    class_<std::vector<G4VPhysicalVolume*>> ("vector of physical volumes")
      .def(vector_indexing_suite<std::vector<G4VPhysicalVolume*>>())
      ;
      
    class_<G4AssemblyVolume, G4AssemblyVolume*, boost::noncopyable>("G4AssemblyVolume", no_init)
        .def(init<G4LogicalVolume*, G4ThreeVector&, G4RotationMatrix*>())
        .def("AddPlacedVolume", f1_AddPlacedVolume)
        .def("AddPlacedVolume", f2_AddPlacedVolume)
        .def("AddPlacedAssembly", f1_AddPlacedAssembly)
        .def("AddPlacedAssembly", f2_AddPlacedAssembly)
        .def("MakeImprint", f1_MakeImprint, (arg("pMotherLV"), arg("translationInMother"), arg("pRotationInMother"), arg("copyNumBase")=0, arg("surfCheck")=false))
        .def("MakeImprint", f2_MakeImprint, (arg("pMotherLV"), arg("transformation"), arg("copyNumBase")=0, arg("surfCheck")=false))
        
        .def("TotalImprintedVolumes", &G4AssemblyVolume::TotalImprintedVolumes)
        .def("GetImprintsCount", &G4AssemblyVolume::GetImprintsCount)
        .def("GetInstanceCount", &G4AssemblyVolume::GetInstanceCount)
        .def("GetAssemblyID", &G4AssemblyVolume::GetAssemblyID)
        .def("GetVolumesIterator", range(&G4AssemblyVolume::GetVolumesIterator, f_GetVolumesIterator_End))
    ;
  }
