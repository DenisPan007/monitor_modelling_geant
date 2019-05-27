#ifndef RunAction_h
#define RunAction_h 1

class Hist1i;

#include "G4UserRunAction.hh"
#include "globals.hh"
class G4Run;

class RunAction: public G4UserRunAction
{
  public:
    RunAction();
   ~RunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void EndOfRunAction(const G4Run*);
    
    void DisplayProgress(G4int);
    void FillDepositedHist1(G4double);
	void FillDepositedHist2(G4double);
	void FillDepositedHist3(G4double);
	void FillCountN1(G4double);
	void FillCountN2(G4double);
	void FillCountN3(G4double);
	
  private:
    G4int eventsNumber;
    G4int printModulo;
    Hist1i* histDeposited1;
	Hist1i* histDeposited2;
	Hist1i* histDeposited3;
	
	Hist1i* histcountN1;
	Hist1i* histcountN2;
	Hist1i* histcountN3;
	

};

#endif
