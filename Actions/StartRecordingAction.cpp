#include "StartRecordingAction.h"
#include "..\ApplicationManager.h"
StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StartRecordingAction::ReadActionParameters() {}
void StartRecordingAction::Execute(bool read_params) {
	if (!pManager->startRecording()) {
		pManager->GetOutput()->PrintMessage("Can't record now, you can call record after a clear all or at the begining of the program");
	}
	else {
		pManager->GetOutput()->PrintMessage("recording started");
	}
}

