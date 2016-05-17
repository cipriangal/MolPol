#include "MolPolSteppingAction.hh"

#include "G4VVisManager.hh"
#include "G4Polyline.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4SteppingManager.hh"

MolPolSteppingAction::MolPolSteppingAction()
:drawFlag(false)
{

}

void MolPolSteppingAction::UserSteppingAction(const G4Step *aStep) {
}


