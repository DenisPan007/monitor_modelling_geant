#include "EventAction.hh"
#include "RunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

EventAction::EventAction() {}

EventAction::~EventAction() {}

void EventAction::EndOfEventAction(const G4Event* event)
{
  // � ����� ������� �������
  RunAction* runAction = (RunAction*) G4RunManager::GetRunManager()->GetUserRunAction();
  
  // ���������� �������� �������������
  runAction->DisplayProgress(event->GetEventID());
}

