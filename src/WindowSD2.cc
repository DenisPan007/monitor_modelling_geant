#include "WindowSD2.hh"
#include "RunAction.hh"

#include "G4RunManager.hh"
#include "G4Step.hh"

using namespace CLHEP;

WindowSD2::WindowSD2(G4String name): G4VSensitiveDetector(name)
{
  // получаем указатель на класс RunAction
  // мы будем вызывать его метод RunAction::FillHist
  // для заполнения гистограммы спектра поглощенной энергии
  runAction = (RunAction*) G4RunManager::GetRunManager()->GetUserRunAction();
}

WindowSD2::~WindowSD2() {}

void WindowSD2::Initialize(G4HCofThisEvent*)
{
  // в начале события сбрасываем энергию поглощенную детектором
    detEnergy2 = 0;
	countN2 = 0;
	
  
}

G4bool WindowSD2::ProcessHits(G4Step* step, G4TouchableHistory*)
//G4bool WindowSD::ProcessHits(G4Track* aTrack, G4TouchableHistory*)
{

 G4Track* track = step->GetTrack();
 G4String particleName = track->GetDefinition()->GetParticleName();
 G4int particleID = track->GetParentID();

  
if (particleName == "e-") {
   if (particleID==0){
 G4double edep = track->GetKineticEnergy();
 detEnergy2 += edep;

 if (edep <= 10*eV){
	 
		countN2 += 1;
			}
   
     // уничтожаем частицу
	//track->SetTrackStatus(fStopAndKill);
	//return fKill;
	
	}
	
	}

    return true;
}

void WindowSD2::EndOfEvent(G4HCofThisEvent*)
{
 
  runAction->FillDepositedHist2(detEnergy2);
  runAction->FillCountN2(countN2);
}

