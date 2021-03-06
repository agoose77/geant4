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
// ====================================================================
//   test09.cc
//
//   test for operators
//
//                                         2005 Q
// ====================================================================
#include <iostream>

class AClass {
private:
  int ival;

public:
  AClass() :ival(999) { }
  AClass(int i) :ival(i) { }
  ~AClass() { }

  void SetIVal(int i) { ival= i; }
  int GetIVal() const { return ival; }

  AClass operator+(const AClass& aclass) {
    AClass atemp;
    atemp.ival= ival + aclass.ival;    
    return atemp;
  }

  AClass& operator+=(const AClass& aclass) {
    ival+= aclass.ival;
    return *this;
  }

  G4bool operator==(const AClass& aclass) const {
    if(ival == aclass.ival) return true;
    return false;
  }
};

std::ostream& operator<<(std::ostream& ostr, const AClass& aclass)
{
  return ostr << aclass.GetIVal();
}


// Boost.Python...
#include <boost/python.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(test09)
{
  class_<AClass>( "AClass", "a class")
    .def(init<>())
    .def(init<int>())
    .add_property("ival", &AClass::GetIVal, &AClass::SetIVal)
    .def(self + self)
    .def(self += self)
    .def(self == self)
    .def(self_ns::str(self))
    ;
}

