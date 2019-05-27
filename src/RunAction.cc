#include "RunAction.hh"
#include "Hist1i.h"

#include "G4Run.hh"
#include "Randomize.hh"

#include "G4ParticleTypes.hh"
#include "G4ParticleDefinition.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

using namespace CLHEP;

RunAction::RunAction() {}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run* run)
{
  eventsNumber = run->GetNumberOfEventToBeProcessed();
  printModulo = eventsNumber/100;
  if (printModulo == 0)
    printModulo = 1;

  // создаем гистограмму
  // от 0 до 1000, с 1000 каналов
  histDeposited1 = new Hist1i(0, 10000, 1000); // energy hist
  histDeposited2 = new Hist1i(0, 10000, 1000); // energy hist
  histDeposited3 = new Hist1i(0, 10000, 1000); // energy hist
  
  histcountN1 = new Hist1i(0, 1000000, 10);
  histcountN2 = new Hist1i(0, 1000000, 10);
  histcountN3 = new Hist1i(0, 1000000, 10);
 
}

void RunAction::DisplayProgress(G4int eventID)
{
  if (eventID%printModulo == 0)
    G4cout << "Progress: " << 100*eventID/eventsNumber << "%\r" << std::flush;
}


void RunAction::FillDepositedHist1(G4double energy1)
{
if (energy1 > 0) {
    // заполняем гистограмму величиной энергии в кэВ
    histDeposited1->fill(energy1/keV);
    
  }
}

void RunAction::FillDepositedHist2(G4double energy2)
{
if (energy2 > 0) {
    // заполняем гистограмму величиной энергии в кэВ
    histDeposited2->fill(energy2/keV);
    
  }
}

void RunAction::FillDepositedHist3(G4double energy3)
{
if (energy3 > 0) {
    // заполняем гистограмму величиной энергии в кэВ
    histDeposited3->fill(energy3/keV);
    
  }
}

void RunAction::FillCountN1(G4double electron1)
{
  if (electron1 > 0) {
    histcountN1->fill(electron1);
  }
}

void RunAction::FillCountN2(G4double electron2)
{
  if (electron2 > 0) {
    histcountN2->fill(electron2);
  }
}

void RunAction::FillCountN3(G4double electron3)
{
  if (electron3 > 0) {
    histcountN3->fill(electron3);
  }
}

void RunAction::EndOfRunAction(const G4Run*)
{

  histDeposited1->save("spectrumEn1.txt", "\"energy, eV\", N");
  histDeposited2->save("spectrumEn2.txt", "\"energy, eV\", N");
  histDeposited3->save("spectrumEn3.txt", "\"energy, eV\", N");
  histcountN1->save("spectrumN1.txt", "\"#e-\", N");
  histcountN2->save("spectrumN2.txt", "\"#e-\", N");
  histcountN3->save("spectrumN3.txt", "\"#e-\", N");
  
  delete histcountN1;
  delete histcountN2;
  delete histcountN3;
  delete histDeposited1;
  delete histDeposited2;
  delete histDeposited3;
 
}

