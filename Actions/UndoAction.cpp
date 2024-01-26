#include "UndoAction.h"
#include "..\ApplicationManager.h"
UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{}

void UndoAction::ReadActionParameters() {}
void UndoAction::Execute(bool read_params) {
	Output* pOut = pManager->GetOutput();
	if (!pManager->UndoLastAction()) {
		pOut->PrintMessage("Can't undo");
	}
	pManager->UpdateInterface();
}

bool UndoAction::canBeRecorded() {
	return true;
}