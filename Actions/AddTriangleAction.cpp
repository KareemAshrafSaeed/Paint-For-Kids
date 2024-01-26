#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Triangle: Click at first vertix");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Triangle: Click at second vertix");
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at third vertix");
	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = pOut->getDrawFilledFigures();
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();
	
	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute(bool read_params)
{
	pManager->GetOutput()->playSound("draw-a-triangle.wav");
	if(read_params) ReadActionParameters();
	AdddedTriangle = new CTriangle(P1, P2, P3, TriangleGfxInfo);
	pManager->AddFigure(AdddedTriangle);
	pManager->clearUndoList();
	pManager->saveUndoAction(this);
}


void AddTriangleAction::Undo() {
	pManager->RemoveFigureByID(AdddedTriangle->getID());
}

void AddTriangleAction::Redo() {
	pManager->AddFigure(AdddedTriangle);
}

bool AddTriangleAction::canBeRecorded() {
	return true;
}

AddTriangleAction::~AddTriangleAction() {
	if (AdddedTriangle->getRelatedActionsCount() - 1 == 0 && AdddedTriangle->getID() == -1)
		delete AdddedTriangle;
	else
		AdddedTriangle->setRelatedActionsCount(AdddedTriangle->getRelatedActionsCount() - 1);
}