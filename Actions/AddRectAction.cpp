#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = pOut->getDrawFilledFigures();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute(bool read_params)
{
	pManager->GetOutput()->playSound("draw-a-rectangle.wav");
	//This action needs to read some parameters first
	if(read_params) ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	AddedRectangle =new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(AddedRectangle);

	pManager->clearUndoList();
	pManager->saveUndoAction(this);
}

void AddRectAction::Undo() {
	pManager->RemoveFigureByID(AddedRectangle->getID());
}

void AddRectAction::Redo() {
	pManager->AddFigure(AddedRectangle);
}

bool AddRectAction::canBeRecorded() {
	return true;
}

AddRectAction::~AddRectAction() {
	if (AddedRectangle->getRelatedActionsCount() - 1 == 0 && AddedRectangle->getID() == -1)
		delete AddedRectangle;
	else
		AddedRectangle->setRelatedActionsCount(AddedRectangle->getRelatedActionsCount() - 1);
}