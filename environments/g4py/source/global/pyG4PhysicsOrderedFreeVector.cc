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
// $Id: pyG4PhysicsVector.cc 101514 2016-11-18 15:30:57Z gcosmo $
// ====================================================================
//   pyG4PhysicsOrderedFreeVector.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4PhysicsVector.hh"
#include "G4PhysicsOrderedFreeVector.hh"
#include "G4MaterialPropertyVector.hh"

using namespace boost::python;

namespace pyG4PhysicsOrderedFreeVector
{
    // Convert iterable e.g boost::python::list to std::vector
    template<typename T>
    inline std::vector<T> iterable_to_std_vector( const object& iterable )
    {
        return std::vector<T>(stl_input_iterator<T>(iterable), stl_input_iterator<T>());
    }
    
    // Ugly factory to build PhysicsOrderedFreeVector
    template <typename V>
    static boost::shared_ptr<V> makeG4PhysicsOrderedFreeVector(list& Energies, list& Values)
    {
        std::vector<double> vec_energies = iterable_to_std_vector<double>(Energies);
        std::vector<double> vec_values = iterable_to_std_vector<double>(Values);
        
        if (vec_energies.size() != vec_values.size())
            throw std::invalid_argument("Dimensions of energies and values do not match");
        
        V* ptr = new V(vec_energies.data(), vec_values.data(), vec_energies.size());
        
        return boost::shared_ptr<V>(ptr);
    }
    
}

using namespace pyG4PhysicsOrderedFreeVector;

// Make the PhysicsOrderedFreeVector classes (MaterialPropertiesVector is simply an alias)
template <typename T>
void make_classes(char const* name, char const* docstring)
{
    class_<T, T*, bases<G4PhysicsVector>>(name, docstring, no_init)

        .def("__init__", make_constructor(makeG4PhysicsOrderedFreeVector<T>))
        .def(init<>())
        
        .def("InsertValues", &T::InsertValues)
        .def("GetEnergy", &T::GetEnergy)
        .def("GetMaxValue", &T::GetMaxValue)
        .def("GetMinValue", &T::GetMinValue)
        .def("GetMaxLowEdgeEnergy", &T::GetMaxLowEdgeEnergy)
        .def("GetMinLowEdgeEnergy", &T::GetMinLowEdgeEnergy)
    ;
}
void export_G4PhysicsOrderedFreeVector()
{
    make_classes<G4PhysicsOrderedFreeVector>("G4PhysicsOrderedFreeVector", "physics ordered free vector class");
    make_classes<G4MaterialPropertyVector>("G4MaterialPropertyVector", "material properties vector class");
};