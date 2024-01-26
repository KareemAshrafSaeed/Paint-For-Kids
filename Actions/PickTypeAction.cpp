#include "PickTypeAction.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

TYPE::TYPE(ApplicationManager* pApp) : Action(pApp)
{
	Correct = 0;
	Wrong = 0;
}

void TYPE::ReadActionParameters()
{}

void TYPE::Execute(bool read_params)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int Count = 0;
	Fig = pManager->randomFigure(Count);

	if (Fig != "Empty")
	{
		pOut->PrintMessage("Select all " + Fig);

		while (Count)
		{
			pIn->GetPointClicked(P.x, P.y);
			CFigure* SelectedFigure = pManager->GetFigure(P.x, P.y);
			if (SelectedFigure)    //to check if user clicked on a figure or not
			{
				if (SelectedFigure->GetType() == Fig)
				{
					Correct++;                                 //if user clicks on the required figure correct ans is incremented
					Count--;                                   //the required figures count is decremented
				}
				else
					Wrong++;                                 // if user clicks on wrong figure wrong answer is incremented

				pOut->ClearDrawArea();                      //to clear drawing area;
				SelectedFigure->SetChoosed(true);                          //calling the function sets choosed to true
				pManager->UpdateInterface();
				printScore();
			} else {
				printScore();
			}
		}

		printScore();

		if (Wrong == 0 && Count == 0) {
			pOut->PrintMessage("                     Congratulation you win                          ");
		}
		pIn->GetUserAction();
		pOut->ClearDrawArea();
		pManager->ShowAll();
		pOut->PrintMessage("It's Play Mode : Please select any icon from the tool bar");
	}

	else
	{
		pOut->PrintMessage("Empty Drawing Area , You can back to \"Draw Mode\" by selecting Draw Icon ");
		return;
	}
}

void TYPE::printScore() {
	pManager->GetOutput()->PrintMessage("Correct Answer = " + to_string(Correct)
		+ " Wrong Answer = " + to_string(Wrong)
		+ " Click any where to continue");
}

