#ifndef WindowSD1_h
#define WindowSD1_h 1

#include "G4VSensitiveDetector.hh"
#include "globals.hh"
class G4Step;
class RunAction;

class WindowSD1: public G4VSensitiveDetector 
{
  public:
    WindowSD1(G4String);
    ~WindowSD1();

    void Initialize(G4HCofThisEvent*);
    G4bool ProcessHits(G4Step*, G4TouchableHistory*);
    void EndOfEvent(G4HCofThisEvent*);
    
  private:
    RunAction* runAction;
	G4double detEnergy1;
	G4double countN1;

};

#endif
