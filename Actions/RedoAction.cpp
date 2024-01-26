#include "RedoAction.h"
#include "..\ApplicationManager.h"
RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{}

void RedoAction::ReadActionParameters() {}
void RedoAction::Execute(bool read_params) {
	Output* pOut = pManager->GetOutput();
	if (!pManager->RedoLastAction()) {
		pOut->PrintMessage("Can't redo");
	}
	pManager->UpdateInterface();
}

bool RedoAction::canBeRecorded() {
	return true;
}