#include"SelectAction.h"
#include"DragAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <Windows.h>

DragAction::DragAction(ApplicationManager* pApp) :Action(pApp)
{
}

void DragAction::ReadActionParameters()
{
	
}

void DragAction::Execute(bool read_params)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	CFigure* FigAct = pManager->getSelectedFigure();
	if (FigAct == NULL) 
	{
		pOut->PrintMessage("Please select figure");
		return;
	}
	FigAct->getCenter(TheOldCenter.x, TheOldCenter.y);
	pOut->PrintMessage("Drag");
	while (pIn->GetButtonState(LEFT_BUTTON, TheOldCenter.x, TheOldCenter.y) == BUTTON_UP)
	{
		
	}
	bool exit2 = !FigAct->belongsToFigure(TheOldCenter);
	bool exit = false;
	while(!exit&&!exit2)
	{
		exit = !pIn->GetButtonState(LEFT_BUTTON, TheNewCenter.x, TheNewCenter.y);
		FigAct->move(TheNewCenter);
		Sleep(3);
		pManager->UpdateInterface();
	}


	
	FigAct = NULL;
	pManager->setSelectedFigure(NULL);
	pOut->ClearStatusBar();
	
	pManager->UpdateInterface();
	
}


