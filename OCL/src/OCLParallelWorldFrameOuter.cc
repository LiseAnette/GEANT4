#include "OCLParallelWorldFrameOuter.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4GDMLParser.hh"
// #include "G4GDMLReadSetup.hh"
#include "G4PhysicalVolumeStore.hh"

OCLParallelWorldFrameOuter::OCLParallelWorldFrameOuter(G4String worldName)
:G4VUserParallelWorld(worldName)
{;}

OCLParallelWorldFrameOuter::~OCLParallelWorldFrameOuter()
{;}

void OCLParallelWorldFrameOuter::Construct()
{
  G4bool useThisParallelWorld = true;

  if (useThisParallelWorld) {
    // Get mass world
    G4VPhysicalVolume* ghostWorld = GetWorld();
    G4LogicalVolume* worldLogical = ghostWorld->GetLogicalVolume();

    // place volumes in the parallel world here.
    // read from CAD
    G4GDMLParser parser;
    // bool flag for reading is for validation -> gives lots of unnecessary warnings
    parser.Read("../OCL/Mesh-Models/frame_outer.gdml", false);
    // remember: each "Wold" volume read with the CAD parser
    // must have a unique name (corresponding to the one used in the gdml file)
    G4LogicalVolume* CADWorldLog = parser.GetVolume("World_frame_outer");

    // set the CAD world volume to
    CADWorldLog->SetMaterial(nullptr);

    // Colors
    G4VisAttributes* VisAtt = new G4VisAttributes(G4Colour(0.95,0.95,0.95, 0.1));
    CADWorldLog->SetVisAttributes(VisAtt);
    for (int i=0; i < CADWorldLog->GetNoDaughters(); i++){
      CADWorldLog->GetDaughter(i)->GetLogicalVolume ()->SetVisAttributes(VisAtt);
    }


    new G4PVPlacement(0, G4ThreeVector(), CADWorldLog,
                      "ParallelWorld Frame Outer", worldLogical, 0, 0);
    }
  else {} // Do nothing
}