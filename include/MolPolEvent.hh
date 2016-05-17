#ifndef __MOLPOLEVENT_HH
#define __MOLPOLEVENT_HH

/*!
   Event information class.  This needs to
   contain all the information we need to
   generate particles and provide sufficient
   output.
*/

#include <vector>
#include "G4ThreeVector.hh"

class G4ParticleDefinition;

class MolPolEvent {
    public:
	 MolPolEvent();
	~MolPolEvent();

	void ProduceNewParticle( G4ThreeVector, G4ThreeVector, G4String );

	void Reset();
	void UndoLastParticle();

	G4bool EventIsSane();
	void   Print();

    private:

    public:
	// Particles to be produced
	std::vector<G4ThreeVector>    fPartPos;
	std::vector<G4ThreeVector>    fPartMom;  // Generated direction (no ms)
	std::vector<G4ParticleDefinition *> fPartType;
};

#endif//__MOLPOLEVENT_HH
