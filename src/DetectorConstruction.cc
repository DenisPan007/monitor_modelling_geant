#include "DetectorConstruction.hh"
#include "WindowSD1.hh"
#include "WindowSD2.hh"
#include "WindowSD3.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4NistManager.hh"
#include "globals.hh"
#include "G4VisAttributes.hh" 
#include "G4SDManager.hh"


using namespace CLHEP;

DetectorConstruction::DetectorConstruction() {}

DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // --- materials ---
  G4NistManager* nistMan = G4NistManager::Instance();
  
//Absorber
  
	G4Material* detMaterial = nistMan->FindOrBuildMaterial("G4_Al");
//	G4Material* worldMaterial = nistMan->FindOrBuildMaterial("G4_Galactic");
G4Material* worldMaterial = nistMan->FindOrBuildMaterial("G4_AIR");
  
  
  
  // --- volumes ---
  G4double worldDiam = 1700*mm; // outer spherer diam
  
  G4double detSize1 = 800.0*mm; // 
  G4double detSize2 = 250.0*mm; //
  G4double detSize3 = 8.0*mm; //
  G4double detSize32 = 2.0*mm; //
  G4double detSize33 = 10.0*mm; //

  G4double gap1 = 510*mm; //  
	G4double gap2 = 11*mm; //
 G4double gap3 = 7*mm; //
 
//world
  G4Box* world_box = new G4Box("world", detSize1/2 + 1*cm, detSize2/2 + 1*cm, (gap1+3*detSize3+2*gap2) + 10*cm);
  G4LogicalVolume* world_log = new G4LogicalVolume(world_box, worldMaterial, "world");
  G4VPhysicalVolume* world_phys = new G4PVPlacement(0, G4ThreeVector(), world_log, "world", 0, false, 0);



// detector1
  G4Box* det1_tube = new G4Box("detector1", detSize1/2, detSize2/2, detSize3/2);
  G4LogicalVolume* det1_log = new G4LogicalVolume(det1_tube, detMaterial, "detector1");
  G4VPhysicalVolume* det1_phys = new G4PVPlacement(0, G4ThreeVector(0,0,-(gap1+(detSize3/2))), det1_log, "detector1", world_log, false, 0);

// detector2
  G4Box* det2_tube = new G4Box("detector2", detSize1/2, detSize2/2, detSize32/2);
  G4LogicalVolume* det2_log = new G4LogicalVolume(det2_tube, detMaterial, "detector2");
  G4VPhysicalVolume* det2_phys = new G4PVPlacement(0, G4ThreeVector(0,0,-(gap1+gap2+detSize3+(detSize32/2))), det2_log, "detector2", world_log, false, 0);

// detector3
  G4Box* det3_tube = new G4Box("detector3", detSize1/2, detSize2/2, detSize33/2);
  G4LogicalVolume* det3_log = new G4LogicalVolume(det3_tube, detMaterial, "detector3");
  G4VPhysicalVolume* det3_phys = new G4PVPlacement(0, G4ThreeVector(0,0,-(gap1+gap2+detSize3+detSize32+gap3+(detSize33/2))), det3_log, "detector3", world_log, false, 0);
  



  // --- sensitive detectors ---
  // регистрируем window_log как детектор
  
  G4SDManager* sdMan = G4SDManager::GetSDMpointer();
  WindowSD1* windowSD1 = new WindowSD1("DetectorSD1");
  
  sdMan->AddNewDetector(windowSD1);
  det1_log->SetSensitiveDetector(windowSD1);
 
 WindowSD2* windowSD2 = new WindowSD2("DetectorSD2");
    sdMan->AddNewDetector(windowSD2);
  det2_log->SetSensitiveDetector(windowSD2);

 WindowSD3* windowSD3 = new WindowSD3("DetectorSD3");
    sdMan->AddNewDetector(windowSD3);
  det3_log->SetSensitiveDetector(windowSD3);
 
 
  
  // --- visualisation ---
 // world_log->SetVisAttributes(G4VisAttributes::Invisible);
//  cover_log->SetVisAttributes(G4VisAttributes::G4VisAttributes(G4Colour::Red()));
//  det_log->SetVisAttributes(G4VisAttributes::G4VisAttributes(G4Colour::Yellow()));
  
  return world_phys;
}
