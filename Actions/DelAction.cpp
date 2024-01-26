#include "DelAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DelAction::DelAction(ApplicationManager* pApp) :Action(pApp) {
	deletedFigure = NULL;
	success = false;
}

void DelAction::ReadActionParameters()
{}

void DelAction::Execute(bool read_params)
{
	Output* pOut = pManager->GetOutput();
	CFigure* SelectedFig = pManager->getSelectedFigure();
	if (SelectedFig != NULL)
	{
		pManager->setSelectedFigure(NULL);
		deletedFigure = SelectedFig;
		deletedFigure->setRelatedActionsCount(deletedFigure->getRelatedActionsCount() + 1);
		pManager->RemoveFigureByID(SelectedFig->getID());
		pOut->PrintMessage("The figure is deleted");
		pManager->clearUndoList();
		pManager->saveUndoAction(this);
		success = true;
	}
	else
		success = false;
		pOut->PrintMessage("Please select a figure first");
}

void DelAction::Undo() {
	pManager->AddFigure(deletedFigure);
}

void DelAction::Redo() {
	pManager->RemoveFigureByID(deletedFigure->getID());
}

bool DelAction::canBeRecorded() {
	return success;
}

DelAction::~DelAction() {
	if (deletedFigure->getRelatedActionsCount() - 1 == 0 && deletedFigure->getID() == -1) {
		delete deletedFigure;
	}
	else {
		deletedFigure->setRelatedActionsCount(deletedFigure->getRelatedActionsCount() - 1);
	}
		
}