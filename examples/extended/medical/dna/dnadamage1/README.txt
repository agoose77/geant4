     =========================================================
 		  Geant4 - dnadamage1 example
     =========================================================

                                README file
                          ----------------------


This is a new exampl and it may contain bugs. If you find a bug, please contact IRSN:
 ngochoang.tran@irsn.fr or carmen.villagrasa@irsn.fr

---->0. INTRODUCTION.                                                    
                                                                       
The dnadamage1 example shows a simple way to simulate dna direct and indirect damages 
using the Geant4-DNA physics and chemical processes in a molecular DNA geometry. 

This example is based on the work described in Sc. Rep. 7 (2017)11923 
and is provided by the Geant4-DNA collaboration.

Any report or published results obtained using the Geant4-DNA software shall 
cite the following Geant4-DNA collaboration publications:
Phys. Med. 31 (2015) 861-874
Med. Phys. 37 (2010) 4692-4708


---->1. GEOMETRY SET-UP.
 
The geometry is chromatical fiber in a 40-nm side cube (Voxel<straight>) made of liquid water (G4_WATER
material). Particles are randomly shot in a cicle of 5 nm2 radius from left side of the cube.

For the DNA chromatical fiber detail, please see: Sc. Rep. 7 (2017) 11923

---->2. SET-UP 
                                                                        
The code can be compiled with cmake.
It works in MT mode.
Chemistry stage is automatically activated. 

---->3. HOW TO RUN THE EXAMPLE                                         

In interactive mode, run:

./dnadamage1
(Note: interactive mode needs at least 6Go of RAM for visualization and may not work correctly in some plateformes)

In batch, the macro dnadamage1.in can be used as bellows. It shows how to shoot different 
particle types and energies.

./dnadamage1 dnadamage1.in

---->4. PHYSICS

This example shows:
- how to use the Geant4-DNA processes (physics and chemistry) through G4EmDNAPhysics and G4EmDNAChemistry_option2 constructors
(look at the PhysicsList.cc file)
- how to count and save energy depositions giving rise to direct damages using an energy thershold 
of 17.5 eV in teh nucleotide backbone region.
(look at the SteppingAction.cc file)
-how to forbid water radicals to be created at the DNA molecule volume (look at the SteppingAction.cc file)
)

---->5. CHEMISTRY

This example shows: 
- how to add a parallel world for chemistry
- how to add a new reaction of free radicals with a DNA molecule using <Step by step model> 
(look at the G4EmDNAChemistry_option2)
- how to count and save occurrences of chemical reactions for indirect damages
(look at to TimeStepAction.cc file)


---->6. SIMULATION OUTPUT AND RESULT ANALYSIS                                    

This file can be easily analyzed using the provided ROOT macro 
file analysis.C (and plot.C, molecule.C); The plot.C results in a text file using the SDD format:
 "A new standard DNA damage (SDD) data format" J. Schuemann et al. Published in Rad. Res. 191 (2019) 76-92
 to do so :
* be sure to have ROOT installed on your machine (version 6 series)
* be sure to be in the directory containing the ROOT files created by dnadamage1
* copy analysis.C (and plot.C, molecule.C) into this directory
* from there, launch ROOT by typing root
* under your ROOT session, type in : .X analysis.C to execute the macro file
* alternatively you can type directly under your session : root -b analysis.C

---------------------------------------------------------------------------

Contact: ngochoang.tran@irsn.fr, carmen.villagrasa@irsn.fr

