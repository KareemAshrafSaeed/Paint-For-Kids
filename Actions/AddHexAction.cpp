#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center of hexagon");
	pIn->GetPointClicked(P.x, P.y);
	HexGfxInfo.isFilled = pOut->getDrawFilledFigures();
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();
}

void AddHexAction::Execute(bool read_params)
{
	pManager->GetOutput()->playSound("draw-a-hexagon.wav");
	if(read_params) ReadActionParameters();
	AddedHexagon = new CHex(P, HexGfxInfo);
	pManager->AddFigure(AddedHexagon);
	pManager->clearUndoList();
	pManager->saveUndoAction(this);
}

void AddHexAction::Undo() {
	pManager->RemoveFigureByID(AddedHexagon->getID());
}

void AddHexAction::Redo() {
	pManager->AddFigure(AddedHexagon);
}

bool AddHexAction::canBeRecorded() {
	return true;
}

AddHexAction::~AddHexAction() {
	if (AddedHexagon->getRelatedActionsCount() - 1 == 0 && AddedHexagon->getID() == -1)
		delete AddedHexagon;
	else
		AddedHexagon->setRelatedActionsCount(AddedHexagon->getRelatedActionsCount() - 1);
}