#include "CHFILLCOL.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CHFILLCOL::CHFILLCOL(ApplicationManager* pApp) :Action(pApp)
{
	success = false;
	ChangedFigure = NULL;
	old_filled = false;
}
void CHFILLCOL::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please choose a color");

	getcolor(pManager->GetUserAction());

	
	pOut->ClearStatusBar();

}
void CHFILLCOL::Execute(bool read_params)
{
	Output* pOut = pManager->GetOutput();
	CFigure* FigAct = pManager->getSelectedFigure();
	if (FigAct == NULL) {
		pOut->PrintMessage("Please select figure");
		success = false;
		return;
	}
	if(read_params) ReadActionParameters();
	ChangedFigure = FigAct;
	ui_old_color = UI.FillColor;
	UI.FillColor = c;
	ui_old_filled = UI.drawFilledFigures;
	UI.drawFilledFigures = true;
	old_color = FigAct->getFillClr();
	old_filled = FigAct->IsFilled();
	FigAct->ChngFillClr(c);
	FigAct = NULL;
	pManager->setSelectedFigure(NULL);
	pManager->UpdateInterface();
	pManager->clearUndoList();
	pManager->saveUndoAction(this);
	success = true;

}
void CHFILLCOL::getcolor(ActionType ActType) {
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
bool CHFILLCOL::canBeRecorded() {
	return success;
}

void CHFILLCOL::Undo() {
	UI.drawFilledFigures = ui_old_filled;
	UI.FillColor = ui_old_color;
	ChangedFigure->ChngFillClr(old_color);
	ChangedFigure->setIsFilled(old_filled);
}

void CHFILLCOL::Redo() {
	UI.drawFilledFigures = true;
	UI.FillColor = c;
	ChangedFigure->ChngFillClr(c);
	ChangedFigure->setIsFilled(true);
}