#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
  gps = new G4GeneralParticleSource();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete gps;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
  gps->GeneratePrimaryVertex(event);
}
