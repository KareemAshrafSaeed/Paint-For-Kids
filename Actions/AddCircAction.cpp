#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Circle: Click at center");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Circle: Click at point on the circle to be drawn");
	pIn->GetPointClicked(P2.x, P2.y);
	CircGfxInfo.isFilled = pOut->getDrawFilledFigures();
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();
}

void AddCircAction::Execute(bool read_params)
{
	pManager->GetOutput()->playSound("draw-a-circle.wav");

	if(read_params) ReadActionParameters();

	AddedCircle = new CCircle(P1, P2, CircGfxInfo);

	pManager->AddFigure(AddedCircle);

	pManager->clearUndoList();
	pManager->saveUndoAction(this);
}

void AddCircAction::Undo() {
	pManager->RemoveFigureByID(AddedCircle->getID());
}

void AddCircAction::Redo() {
	pManager->AddFigure(AddedCircle);
}

bool AddCircAction::canBeRecorded() {
	return true;
}

AddCircAction::~AddCircAction() {
	if (AddedCircle->getRelatedActionsCount() - 1 == 0 && AddedCircle->getID() == -1) {
		delete AddedCircle;
	}
	else {
		AddedCircle->setRelatedActionsCount(AddedCircle->getRelatedActionsCount() - 1);
	}
}