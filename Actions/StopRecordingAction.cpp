#include "StopRecordingAction.h"
#include "..\ApplicationManager.h"
StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StopRecordingAction::ReadActionParameters() {}

void StopRecordingAction::Execute(bool read_params) {
	if (!pManager->stopRecording()) {
		pManager->GetOutput()->PrintMessage("Can't stop recording without starting a record");
	}
	else {
		pManager->GetOutput()->PrintMessage("Recording is stoped successfully");
	}
}

