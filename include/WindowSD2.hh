#ifndef WindowSD2_h
#define WindowSD2_h 1

#include "G4VSensitiveDetector.hh"
#include "globals.hh"
class G4Step;
class RunAction;

class WindowSD2: public G4VSensitiveDetector 
{
  public:
    WindowSD2(G4String);
    ~WindowSD2();

    void Initialize(G4HCofThisEvent*);
    G4bool ProcessHits(G4Step*, G4TouchableHistory*);
    void EndOfEvent(G4HCofThisEvent*);
    
  private:
    RunAction* runAction;
	G4double detEnergy2;
	G4double countN2;

};

#endif
