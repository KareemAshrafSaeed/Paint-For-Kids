#include"SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("please select a figure point");
	pIn->GetPointClicked(PClicked.x, PClicked.y);
}

void SelectAction::Execute(bool read_params)
{
	if(read_params) ReadActionParameters();
	CFigure * SelectedFigure = pManager->GetFigure(PClicked.x, PClicked.y);
	if (SelectedFigure == NULL) 
		pManager->GetOutput()->PrintMessage("you didn't click on a figure");
	else {
		if (pManager->getSelectedFigure() == SelectedFigure) SelectedFigure = NULL;
		pManager->setSelectedFigure(SelectedFigure);
		if(SelectedFigure != NULL)
		SelectedFigure->PrintInfo(pManager->GetOutput());
	}

	pManager->UpdateInterface();
}

bool SelectAction::canBeRecorded() {
	return true;
}