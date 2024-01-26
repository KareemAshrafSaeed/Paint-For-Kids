#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Load Graph, please enter file name ");

	filename = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void LoadAction::Execute(bool read_params)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ifstream infile; //this is our cin
	infile.open(filename+".txt"); //attempt to open the file
	if (infile) //verify that the file actually opened
	{
		
		pManager->ClearAll();
		CFigure* Fig;
		int NumberOfFigures;
		string draw_color, fill_color;
		infile >> draw_color >> fill_color;
		pOut->setDrwColorLoad(draw_color);
		pOut->setFilColorLoad(fill_color);
		infile >> NumberOfFigures;
		for (int i = 0; i < NumberOfFigures; i++)
		{
			string type;
			infile >> type;
			if (type == "RECT")
			{
				Fig = new CRectangle;
				Fig->Load(infile);
				pManager->AddFigure(Fig);
			}
			else if (type == "Circ")
			{
				Fig = new CCircle;
				Fig->Load(infile);
				pManager->AddFigure(Fig);
			}
			else if (type == "HEXAGON")
			{
				Fig = new CHex;
				Fig->Load(infile);
				pManager->AddFigure(Fig);
			}
			else if (type == "TRIANGLE")
			{
				Fig = new CTriangle;
				Fig->Load(infile);
				pManager->AddFigure(Fig);
			}
			else if (type == "SQUARE")
			{
				Fig = new CSquare;
				Fig->Load(infile);
				pManager->AddFigure(Fig);
			}
		}
		infile.close();
	}
	else
	{
		pOut->PrintMessage("File doesn't exist");
	}
}
