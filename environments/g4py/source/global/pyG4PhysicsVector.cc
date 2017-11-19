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
//   pyG4PhysicsVector.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include <boost/python/exception_translator.hpp>
#include "G4PhysicsVector.hh"
#include <exception>


using namespace boost::python;


namespace pyPhysicsVectorIterator
{
    struct py_stop_iteration : std::exception
    {
      const char* what() const throw() { return ""; }
    };
    
    void translate(py_stop_iteration const& e)
    {
        // Use the Python 'C' API to set up an exception object
        PyErr_SetString(PyExc_StopIteration, e.what());
    };
    
    // Python iterator over Vector object with [] operator and GetVectorLength method
    // Yielding G4double
    template <typename V>
    class pyVectorIterator
    {
        private:
            size_t index;
            V* vec;
            
        public:
            // Make an proxyable python iterator for the given vector class V over the object vec
            static pyVectorIterator<V>* factory(V* vec)
            {
                return new pyVectorIterator<V>(vec);
            }
        
            pyVectorIterator(V* vec_): vec(vec_), index(0){};
            
            // Define the next method for the iterator class (to be called by python)
            G4double next()
            {
                if (index < vec->GetVectorLength())
                {
                    G4double result = (*vec)[index];
                    index ++;
                    return result;
                }
                throw py_stop_iteration();
            };
    };
    
    // Make iterator known to Python by creating a boost::python::class_<> instance
    template <typename V>
    static void export_iterator(const char* name)
    {
        typedef pyVectorIterator<V> it_type;
        
        class_<it_type>(name, no_init)
            .def("__next__", &it_type::next)
          ;
    }
    
}

namespace pyG4PhysicsVector
{  
    tuple f1_Value(const G4PhysicsVector* vect, G4double theEnergy)
    {
        size_t lastidx;
        G4double result = vect->Value(theEnergy, lastidx);
        return boost::python::make_tuple(result, lastidx);
    };
    
    G4double f2_Value(const G4PhysicsVector* vect, G4double theEnergy)
    {
        return vect->Value(theEnergy);
    };
    
    G4double f_GetItem(const G4PhysicsVector& vec, size_t i)
    {
        return vec[i];
    };
    
    list f_GetSlice(const G4PhysicsVector& vec, slice s)
    {
        list items;
        long start, stop, step;
        
        if (s.start() == object())
            start = 0;
        else
            start = extract<long>(s.start());
            
        if (s.stop() == object())
            stop = vec.GetVectorLength();
        else
            stop = extract<long>(s.stop());
        
        if (s.step() == object())
            step = 1;
        else
            step = extract<long>(s.step());
            
        for (int i=start; i<stop; i=i+step)
            items.append(vec[i]); 
            
        return items;
    };
            
    size_t f_Len(const G4PhysicsVector& vec)
    {
        return vec.GetVectorLength();
    };    
    
}

using namespace pyPhysicsVectorIterator;
using namespace pyG4PhysicsVector;

void export_G4PhysicsVector()
{
    register_exception_translator<py_stop_iteration>(translate);
    export_iterator<G4PhysicsVector>("G4PhysicsVectorIterator");
  
    class_<G4PhysicsVector, G4PhysicsVector*, boost::noncopyable>
        ("G4PhysicsVector", "vector class", no_init)

        .def(init<const G4PhysicsVector&>())
        .def(init<G4bool>(arg("spline")=false))

        .def(self == self)
        .def(self != self)
        
        .def("__getitem__", f_GetItem)
        .def("__getitem__", f_GetSlice)
        .def("__len__", f_Len)
        .def("__iter__", pyVectorIterator<G4PhysicsVector>::factory, return_value_policy<manage_new_object>())

        .def("ValuePair", f1_Value)
        .def("Value", f2_Value)
        .def("PutValue", &G4PhysicsVector::PutValue)
        .def("ScaleVector", &G4PhysicsVector::ScaleVector)
        .def("Energy", &G4PhysicsVector::Energy)
        .def("GetMaxEnergy", &G4PhysicsVector::GetMaxEnergy)
        .def("GetVectorLength", &G4PhysicsVector::GetVectorLength)
        .def("FindBin", &G4PhysicsVector::FindBin)
        .def("FillSecondDerivatives", &G4PhysicsVector::FillSecondDerivatives)
        .def("ComputeSecDerivatives", &G4PhysicsVector::ComputeSecDerivatives)
        .def("ComputeSecondDerivatives", &G4PhysicsVector::ComputeSecondDerivatives)
        .def("FindLinearEnergy", &G4PhysicsVector::FindLinearEnergy)
        .def("IsFilledVectorExist", &G4PhysicsVector::IsFilledVectorExist)
        .def("GetType", &G4PhysicsVector::GetType)
        .def("SetSpline", &G4PhysicsVector::SetSpline)
        .def("DumpValues", &G4PhysicsVector::DumpValues, (arg("unitE")=1.0, arg("unitV")=1.0))
        .def("SetVerboseLevel", &G4PhysicsVector::SetVerboseLevel)
    ;
    // ---
    enum_<G4PhysicsVectorType>("G4PhysicsVectorType")
        .value("T_G4PhysicsVector", T_G4PhysicsVector)
        .value("T_G4PhysicsLinearVector", T_G4PhysicsLinearVector)
        .value("T_G4PhysicsLogVector", T_G4PhysicsLogVector)
        .value("T_G4PhysicsLnVector", T_G4PhysicsLnVector)
        .value("T_G4PhysicsFreeVector", T_G4PhysicsFreeVector)
        .value("T_G4PhysicsOrderedFreeVector", T_G4PhysicsOrderedFreeVector)
        .value("T_G4LPhysicsFreeVector", T_G4PhysicsOrderedFreeVector)
    ;
    
}