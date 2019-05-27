#include "WindowSD3.hh"
#include "RunAction.hh"

#include "G4RunManager.hh"
#include "G4Step.hh"

using namespace CLHEP;

WindowSD3::WindowSD3(G4String name): G4VSensitiveDetector(name)
{
  // �������� ��������� �� ����� RunAction
  // �� ����� �������� ��� ����� RunAction::FillHist
  // ��� ���������� ����������� ������� ����������� �������
  runAction = (RunAction*) G4RunManager::GetRunManager()->GetUserRunAction();
}

WindowSD3::~WindowSD3() {}

void WindowSD3::Initialize(G4HCofThisEvent*)
{
  // � ������ ������� ���������� ������� ����������� ����������
    detEnergy3 = 0;
	countN3 = 0;
	
  
}

G4bool WindowSD3::ProcessHits(G4Step* step, G4TouchableHistory*)
//G4bool WindowSD::ProcessHits(G4Track* aTrack, G4TouchableHistory*)
{

 G4Track* track = step->GetTrack();
 G4String particleName = track->GetDefinition()->GetParticleName();
 G4int particleID = track->GetParentID();

  
if (particleName == "e-") {
   
   if (particleID==0){
 G4double edep = track->GetKineticEnergy();
 detEnergy3 += edep;

 if (edep <= 10*eV){
	 
		countN3 += 1;
			}
   
     // ���������� �������
	//track->SetTrackStatus(fStopAndKill);
	//return fKill;
	
	
	}
    }
    return true;
}

void WindowSD3::EndOfEvent(G4HCofThisEvent*)
{
 
  runAction->FillDepositedHist3(detEnergy3);
  runAction->FillCountN3(countN3);
}

