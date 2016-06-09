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
//
// File name:     RadmonDetectorFlatVolumeComponent.hh
// Creation date: Sep 2005
// Main author:   Riccardo Capra <capra@ge.infn.it>
//
// Id:            $Id: RadmonDetectorFlatVolumeComponent.hh,v 1.4 2006/06/29 16:09:27 gunter Exp $
// Tag:           $Name: geant4-09-01 $
//
// Description:   Component to create a box
//

#ifndef   RADMONDETECTORFLATVOLUMECOMPONENT_HH
 #define  RADMONDETECTORFLATVOLUMECOMPONENT_HH
 
 // Include files
 #include "globals.hh"
 
 // Forward declarations
 class RadmonVDetectorLabelledEntityConstructor;
 class RadmonDetectorLayerVolumesList;
 class G4Box;
 class G4VisAttributes;
 
 class RadmonDetectorFlatVolumeComponent
 {
  public:
   inline                                       RadmonDetectorFlatVolumeComponent(const RadmonVDetectorLabelledEntityConstructor * constructor);
                                               ~RadmonDetectorFlatVolumeComponent();
   RadmonDetectorLayerVolumesList *             GenerateVolumesList(void);

  private:
  // Hidden constructors and operators
                                                RadmonDetectorFlatVolumeComponent();
                                                RadmonDetectorFlatVolumeComponent(const RadmonDetectorFlatVolumeComponent & copy);
   RadmonDetectorFlatVolumeComponent &          operator=(const RadmonDetectorFlatVolumeComponent & copy);

  // Private attributes
   const RadmonVDetectorLabelledEntityConstructor * owner;
   G4Box *                                      box;
   G4VisAttributes *                            visAttributes;
 };
 
 // Inline implementations
 #include "RadmonDetectorFlatVolumeComponent.icc"
#endif /* RADMONDETECTORFLATVOLUMECOMPONENT_HH */