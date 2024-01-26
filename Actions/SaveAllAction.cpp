#include "SaveAllAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SaveAllAction::SaveAllAction(ApplicationManager* pApp) : Action(pApp)
{}

void SaveAllAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Saving graph please enter filename to save figures");

	filename = pIn->GetSrting(pOut);
	filename += ".txt";
	pOut->ClearStatusBar();

}

//Execute the action
void SaveAllAction::Execute(bool read_params)
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ofstream file(filename);
	string fill_color = pOut->getColorName(UI.FillColor);
	if (!UI.drawFilledFigures) fill_color = "NO_FILL";
	file << pOut->getColorName(UI.DrawColor) << '\t' << fill_color <<endl;
	pManager->SaveAll(file);
}
