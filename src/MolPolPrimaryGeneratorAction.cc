#include "MolPolPrimaryGeneratorAction.hh"
#include "MolPolMessenger.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "Randomize.hh"
#include "MolPolIO.hh"
//#include <iostream>

//using namespace std;

MolPolPrimaryGeneratorAction::MolPolPrimaryGeneratorAction()
  :rndmFlag("off")
{
  //cout << "MolPolPrimaryGeneratorAction::MolPolPrimaryGeneratorAction" << endl;
  G4int n_particle = 1;
  particleGun  = new G4ParticleGun(n_particle);
  
  //create a messenger for this class
  //gunMessenger = new MolPolMessenger(this);

  // default particle kinematic

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="e-");
  particleGun->SetParticleDefinition(particle);
  angle = 0;
  particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  particleGun->SetParticleEnergy(105.*MeV);
  //G4double position = -0.5*(Detector->GetWorldSizeX());
  particleGun->SetParticlePosition(G4ThreeVector(0*cm,0.*cm,0.*cm));

}

MolPolPrimaryGeneratorAction::~MolPolPrimaryGeneratorAction()
{
  delete particleGun;
  delete gunMessenger;
}
void MolPolPrimaryGeneratorAction::rand(){ 
  //G4ThreeVector pos = Simulation::getInstance()->detector->randPos();
  //particleGun->SetParticlePosition(pos);
}
void MolPolPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  particleGun->GeneratePrimaryVertex(anEvent);
}

void MolPolPrimaryGeneratorAction::SourceModeSet(G4int i) {
//      SourceModeSet(0); // point to the one below with default settings = 0. // should I just use default parameters?
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
