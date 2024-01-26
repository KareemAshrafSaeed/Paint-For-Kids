#include "ToDrawModeAction.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"


ToDrawModeAction::ToDrawModeAction(ApplicationManager* pApp) :Action(pApp)
{}

void ToDrawModeAction::ReadActionParameters()
{}

void ToDrawModeAction::Execute(bool read_params)
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();

	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();

	pManager->ShowAll();

	UI.InterfaceMode = MODE_DRAW;

}