#include "Pick_Type_ColorAction.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

Pick_Type_Color::Pick_Type_Color(ApplicationManager* pApp) : Action(pApp)
{
	 Correct=0;
	 Wrong=0;
}

void Pick_Type_Color::ReadActionParameters()
{}

void Pick_Type_Color::Execute(bool read_params)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int Count = 0;
	Fig = pManager->randomFigureColor(Count, PlayingColor,NameColor);

	if (PlayingColor != WHITE && Fig != "Empty")
	{
		pOut->PrintMessage("Select all "+ NameColor + " " + Fig);

		while (Count)
		{
			pIn->GetPointClicked(P.x, P.y);
			CFigure* SelectedFigure = pManager->GetFigure(P.x, P.y);
			if (SelectedFigure)      //to check if user clicked on a figure or not
			{
				if (SelectedFigure->GetColor() == PlayingColor && SelectedFigure->GetType() == Fig)
				{
					Correct++;   //if user clicks on the required figure correct answer is incremented
					Count--;  //the required figures count is decremented
				}
				else
					Wrong++; // if user clicks on wrong figure wrong answer is incremented

				pOut->ClearDrawArea();                      //to clear drawing area;
				SelectedFigure->SetChoosed(true);  //calling the function sets choosed to true 
				pManager->UpdateInterface();
				pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "                                              "
					+ "Wrong Ans = " + to_string(Wrong));
			}

			else {
				printScore();


			}
		}

		printScore();

		if (Wrong == 0 && Count == 0) {
			pOut->PrintMessage("                     Congratulation you win                            ");
		}

		pIn->GetUserAction();
		pOut->ClearDrawArea();
		pManager->ShowAll();
		pOut->PrintMessage("It's Play Mode : Please select any icon from the tool bar");
	}
	else
	{
		pOut->PrintMessage("There aren't any Colored Figures , Select another icon from toolbar");
		return;
	}
}

void Pick_Type_Color::printScore() {
	pManager->GetOutput()->PrintMessage("Correct Answer = " + to_string(Correct)
		+ " Wrong Answer = " + to_string(Wrong)
		+ " Click any where to continue ... ");
}