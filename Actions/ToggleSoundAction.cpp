#include "ToggleSoundAction.h"
#include "..\ApplicationManager.h"
ToggleSoundAction::ToggleSoundAction(ApplicationManager* pApp) : Action(pApp)
{}

void ToggleSoundAction::ReadActionParameters() {}
void ToggleSoundAction::Execute(bool read_params) {
	Output* pOut = pManager->GetOutput();
	bool is_on = pOut->toggleSound();
	if(is_on)
		pOut->PrintMessage("Sound is turned on");
	else
		pOut->PrintMessage("Sound is turned off");
}

