#include"SelectAction.h"
#include"MoveAction.h"

#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

MoveAction:: MoveAction(ApplicationManager* pApp) : Action(pApp){
	success = false;
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("click on a location to move selected figures !");
	pIn->GetPointClicked(thenewcenter.x, thenewcenter.y);
}
void MoveAction::Execute(bool read_params)
{
	Output* pOut = pManager->GetOutput();
	if(read_params) ReadActionParameters();
	CFigure* FigAct = pManager->getSelectedFigure();
	if (FigAct == NULL) {
		pOut->PrintMessage("Please select figure");
		success = false;
		return;
	}

	MovedFigure = FigAct;
	FigAct->getCenter(theoldcenter.x, theoldcenter.y);
	FigAct->move(thenewcenter);
	FigAct = NULL;
	pManager->setSelectedFigure(NULL);
	pOut->ClearStatusBar();
	
	pManager->UpdateInterface();
	pManager->clearUndoList();
	pManager->saveUndoAction(this);
	success = true;
}
bool MoveAction::canBeRecorded() {
	return success;
}

void MoveAction::Undo() {
	MovedFigure->move(theoldcenter);
}

void MoveAction::Redo() {
	MovedFigure->move(thenewcenter);
}