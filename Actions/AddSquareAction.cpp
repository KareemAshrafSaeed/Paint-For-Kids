#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddSquareAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center of square");
	pIn->GetPointClicked(P.x, P.y);

	SquareGfxInfo.isFilled = pOut->getDrawFilledFigures();
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute(bool read_params)
{
	pManager->GetOutput()->playSound("draw-a-square.wav");
	if(read_params) ReadActionParameters();
	AddedSquare = new CSquare(P, SquareGfxInfo);
	pManager->AddFigure(AddedSquare);
	pManager->clearUndoList();
	pManager->saveUndoAction(this);
}

void AddSquareAction::Undo() {
	pManager->RemoveFigureByID(AddedSquare->getID());
}

void AddSquareAction::Redo() {
	pManager->AddFigure(AddedSquare);
}

bool AddSquareAction::canBeRecorded() {
	return true;
}


AddSquareAction::~AddSquareAction() {
	if (AddedSquare->getRelatedActionsCount() - 1 == 0 && AddedSquare->getID() == -1)
		delete AddedSquare;
	else
		AddedSquare->setRelatedActionsCount(AddedSquare->getRelatedActionsCount() - 1);
}