#include "CHDRCOL.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CHDRCOL::CHDRCOL(ApplicationManager* pApp) :Action(pApp)
{
	ChangedFigure = NULL;
	success = false;
}
void CHDRCOL::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please choose a color");
	
	getcolor(pManager->GetUserAction());

	pOut->ClearStatusBar();
	
}
void CHDRCOL::Execute(bool read_params)
{
	Output* pOut = pManager->GetOutput();
	CFigure* FigAct = pManager->getSelectedFigure();
	if (FigAct == NULL) {
		pOut->PrintMessage("Please select figure");
		success = false;
		return;
	}
	if(read_params) ReadActionParameters();
	old_color = FigAct->getDrawClr();
	ChangedFigure = FigAct;
	FigAct->ChngDrawClr(c);
	ui_old_color = UI.DrawColor;
	UI.DrawColor = c;
	FigAct = NULL;
	pManager->setSelectedFigure(NULL);
	pManager->UpdateInterface();
	pOut->ClearStatusBar();
	pManager->clearUndoList();
	pManager->saveUndoAction(this);
	success = true;
}
void CHDRCOL::getcolor(ActionType ActType) {
	switch (ActType)
	{
	case BLACK_COLOR:
		
		c = BLACK;
		break;

	case YELLOW_COLOR:
		
		c = YELLOW;
		break;

	case ORANGE_COLOR:
		
		c = ORANGE;
		break;


	case RED_COLOR:
		
		c = RED;
		break;


	case GREEN_COLOR:
		
		c = GREEN;
		break;



	case BLUE_COLOR:
		
		c = BLUE;
		break;
	}
}
bool CHDRCOL::canBeRecorded() {
	return success;
}

void CHDRCOL::Undo() {
	UI.DrawColor = ui_old_color;
	ChangedFigure->ChngDrawClr(old_color);
}

void CHDRCOL::Redo() {
	UI.DrawColor = c;
	ChangedFigure->ChngDrawClr(c);
}