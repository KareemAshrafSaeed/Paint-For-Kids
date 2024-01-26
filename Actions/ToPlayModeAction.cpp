#include "ToPlayModeAction.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{}

void ToPlayModeAction::ReadActionParameters()
{}

void ToPlayModeAction::Execute(bool read_params)
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();

	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();

	UI.InterfaceMode = MODE_PLAY;

}