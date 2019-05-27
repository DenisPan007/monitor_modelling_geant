#include "EventAction.hh"
#include "RunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

EventAction::EventAction() {}

EventAction::~EventAction() {}

void EventAction::EndOfEventAction(const G4Event* event)
{
  // в конце каждого события
  RunAction* runAction = (RunAction*) G4RunManager::GetRunManager()->GetUserRunAction();
  
  // отображаем прогресс моделирования
  runAction->DisplayProgress(event->GetEventID());
}

