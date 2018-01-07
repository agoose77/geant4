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
// $Id: pyG4Material.cc 76884 2013-11-18 12:54:03Z gcosmo $
// ====================================================================
//   pyG4Material.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
# include <boost/python/suite/indexing/map_indexing_suite.hpp>
# include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <exception>
#include <vector>

#include "G4Version.hh"
#include "G4MaterialPropertiesTable.hh"

using namespace boost::python;


namespace pyG4MaterialPropertiesTable
{

    template<typename T>
    inline std::vector<T> to_std_vector( const object& iterable )
    {
        return std::vector<T>(stl_input_iterator<T>(iterable), stl_input_iterator<T>());
    }

    // Converts a C++ map to a python dict
    template <class K, class V>
    dict std_map_to_dict(std::map<K, V> map) {
        typename std::map<K, V>::iterator iter;
        dict dictionary;
        for (iter = map.begin(); iter != map.end(); ++iter) {
            dictionary[iter->first] = iter->second;
        }
        return dictionary;
    }

    G4MaterialPropertyVector* f1_AddProperty(G4MaterialPropertiesTable* table, const char *key, list& PhotonEnergies, list& PropertyValues)
    {
        std::vector<double> vec_energies = to_std_vector<double>(PhotonEnergies);
        std::vector<double> vec_values = to_std_vector<double>(PropertyValues);

        if (vec_energies.size() != vec_values.size())
            throw std::invalid_argument("Dimensions of photon energies and property values do not match");

        G4MaterialPropertyVector* result = table->AddProperty(key, vec_energies.data(), vec_values.data(), vec_energies.size());
        return result;
    }
    void f2_AddProperty(G4MaterialPropertiesTable* table, const char* key, G4MaterialPropertyVector* vec)
    {
        table->AddProperty(key, vec);
    }

    // Unlike API, returns a copy
    dict f_GetPropertiesMap(G4MaterialPropertiesTable* table)
    {
        return std_map_to_dict<G4String, G4MaterialPropertyVector*>(*table->GetPropertiesMap());
    }

    // Unlike API, returns a copy
    dict f_GetPropertiesCMap(G4MaterialPropertiesTable* table)
    {
        return std_map_to_dict<G4String, G4double>(*table->GetPropertiesCMap());
    }

}

using namespace pyG4MaterialPropertiesTable;

// ====================================================================
// module definition
// ====================================================================
void export_G4MaterialPropertiesTable()
{
    class_<G4MaterialPropertiesTable, G4MaterialPropertiesTable*, boost::noncopyable>
    ("G4MaterialPropertiesTable", "material properties table class", no_init)
    .def(init<>())
    // ---
    .def("AddConstProperty", &G4MaterialPropertiesTable::AddConstProperty)
    .def("AddProperty", f1_AddProperty,
     return_internal_reference<>())
    .def("AddProperty", f2_AddProperty)
    .def("RemoveConstProperty", &G4MaterialPropertiesTable::RemoveConstProperty)
    .def("RemoveProperty", &G4MaterialPropertiesTable::RemoveProperty)
    .def("GetConstProperty", &G4MaterialPropertiesTable::GetConstProperty)
    .def("ConstPropertyExists", &G4MaterialPropertiesTable::ConstPropertyExists)
    .def("GetProperty", &G4MaterialPropertiesTable::GetProperty,
     return_internal_reference<>())
    .def("AddEntry", &G4MaterialPropertiesTable::AddEntry)
    .def("DumpTable", &G4MaterialPropertiesTable::DumpTable)
    .def("GetPropertiesMap", f_GetPropertiesMap)
    .def("GetPropertiesCMap", f_GetPropertiesCMap)
    ;
}
