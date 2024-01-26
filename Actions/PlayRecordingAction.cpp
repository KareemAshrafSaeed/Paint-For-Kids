#include "PlayRecordingAction.h"
#include "..\ApplicationManager.h"
PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void PlayRecordingAction::ReadActionParameters() {}

void PlayRecordingAction::Execute(bool read_params) {
	if (!pManager->playRecordedActions()) {
		pManager->GetOutput()->PrintMessage("There are no Recorded Actions");
	}
	else {
		pManager->GetOutput()->PrintMessage("Recording is played successfully");
	}
}

