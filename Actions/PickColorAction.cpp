#include "PickColorAction.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

PickColor::PickColor(ApplicationManager* pApp) : Action(pApp)
{
	Correct = 0;
	Wrong = 0;
}

void PickColor::ReadActionParameters()
{}

void PickColor::Execute(bool read_params)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int Count = 0;
	NameColor = pManager->randomColor(Count, PlayingColor);
	

	if (NameColor != "No_Fill")
	{
		pOut->PrintMessage("Select all "+ NameColor + " Figures");

		while (Count)
		{

			pIn->GetPointClicked(P.x, P.y);
			CFigure* SelectedFigure = pManager->GetFigure(P.x, P.y);
			if (SelectedFigure)   //to check if user clicked on a figure or not
			{
				if (SelectedFigure->GetColor() == PlayingColor)
				{
					Correct++;    //if user clicks on the required figure correct ans is incremented
					Count--;      //the required figures count is decremented
				}
				else
					Wrong++;    // if user clicks on wrong figure wrong answer is incremented

				pOut->ClearDrawArea();  //to clear drawing area;
				SelectedFigure->SetChoosed(true); //calling the function sets choosed to true 
				pManager->UpdateInterface();

				printScore();
			}
			else
			{
				printScore();
			}
		}

		printScore();

		if (Wrong == 0 && Count == 0) {
			pOut->PrintMessage("                          Congratulations you win                ");
		} 

		pIn->GetUserAction();
		pOut->ClearDrawArea();
		pManager->ShowAll();
		pOut->PrintMessage("Play Mode : Please select any icon to start playing");
	}
	else
	{
		pOut->PrintMessage("There aren't any Colored Figures , Select another icon or draw more colored figures");
		return;
	}



}

void PickColor::printScore() {
	pManager->GetOutput()->PrintMessage("Correct Answer = " + to_string(Correct)
		+ " Wrong Answer = " + to_string(Wrong)
		+ " Click any where to continue ... ");
}