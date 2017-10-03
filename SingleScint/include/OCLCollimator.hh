#ifndef OCLCOLLIMATOR_H
#define OCLCOLLIMATOR_H 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "G4SystemOfUnits.hh"

#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"

#include "G4Material.hh"


#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4UnionSolid.hh"
// #include "G4Material.hh"
// #include "G4NistManager.hh"
// #include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
// #include "G4SystemOfUnits.hh"
// #include "G4Transform3D.hh"
// #include "G4PhysicalConstants.hh"

#include "G4Colour.hh"

#include "G4LogicalBorderSurface.hh"
#include "G4OpticalSurface.hh"


/// Detector construction class to define materials and geometry.
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4PVPlacement;
class G4Box;


class OCLCollimator {

public:
  OCLCollimator();
  ~OCLCollimator();

public:
  void SetPosition( G4ThreeVector );
  void SetRotation( G4RotationMatrix );
  void Placement(G4int, G4VPhysicalVolume*, G4bool);

private:
  G4ThreeVector        translatePos;
  G4RotationMatrix     rotation;


G4Material* lead ;

G4Cons* solidCollimator;
G4LogicalVolume* logicCollimator;

G4ThreeVector positionCollimator;
G4VPhysicalVolume* physiCollimator;

private:
  void CreateSolids();
  // void MakeMaterials();

};

#endif