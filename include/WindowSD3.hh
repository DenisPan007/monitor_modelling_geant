#ifndef WindowSD3_h
#define WindowSD3_h 1

#include "G4VSensitiveDetector.hh"
#include "globals.hh"
class G4Step;
class RunAction;

class WindowSD3: public G4VSensitiveDetector 
{
  public:
    WindowSD3(G4String);
    ~WindowSD3();

    void Initialize(G4HCofThisEvent*);
    G4bool ProcessHits(G4Step*, G4TouchableHistory*);
    void EndOfEvent(G4HCofThisEvent*);
    
  private:
    RunAction* runAction;
	G4double detEnergy3;
	G4double countN3;

};

#endif
