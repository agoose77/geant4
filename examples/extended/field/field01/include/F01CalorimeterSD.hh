//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: F01CalorimeterSD.hh,v 1.3 2001/10/15 17:20:34 gcosmo Exp $
// GEANT4 tag $Name: geant4-04-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef F01CalorimeterSD_h
#define F01CalorimeterSD_h 1

#include "globals.hh"
#include "G4VSensitiveDetector.hh"
#include "F01CalorHit.hh"

class F01DetectorConstruction;
class G4HCofThisEvent;
class G4Step;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class F01CalorimeterSD : public G4VSensitiveDetector
{
  public:
  
      F01CalorimeterSD(G4String, F01DetectorConstruction* );
     ~F01CalorimeterSD();

      void Initialize(G4HCofThisEvent*);
      G4bool ProcessHits(G4Step*,G4TouchableHistory*);
      void EndOfEvent(G4HCofThisEvent*);
      void clear();
      void PrintAll();

  private:
  
      F01CalorHitsCollection*  CalCollection;      
      F01DetectorConstruction* Detector;
      G4int*                   HitID;
};

#endif
