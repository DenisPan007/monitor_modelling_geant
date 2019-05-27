#include "DetectorConstruction.hh"
//#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
//#include "StackingAction.hh"

//#include "QGSP_BERT_HP.hh"
//#include "FTFP_BERT_HP.hh"
//#include "FTFP_BERT.hh"
#include "LHEP.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Randomize.hh"
#include <ctime>

int main(int argc, char** argv)
{
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  CLHEP::HepRandom::setTheSeed(time(NULL));

  G4RunManager* runManager = new G4RunManager;

  // подключение обязательных классов
//    G4VModularPhysicsList* physList = new QGSP_BERT_HP;
//  G4VModularPhysicsList* physList = new FTFP_BERT_HP(0);
//  G4VModularPhysicsList* physList = new FTFP_BERT(0);
  G4VModularPhysicsList* physList = new LHEP;
  runManager->SetUserInitialization(physList);

  runManager->SetUserInitialization(new DetectorConstruction);
  runManager->SetUserAction(new PrimaryGeneratorAction);

  // подключение дополнительных классов
  runManager->SetUserAction(new RunAction);
  runManager->SetUserAction(new EventAction);
  //runManager->SetUserAction(new StackingAction);

  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  
  runManager->Initialize();
  
  // запуск конфигурационного файла
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ExecuteMacroFile(argv[1]);
  
  delete visManager;
  delete runManager;
  return 0;
}
