#include "CSquare.h"

CSquare::CSquare() :CFigure() {}

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE" << "\t"
		<< ID << "\t"
		<< Center.x << "\t"
		<< Center.y << "\t"
		<< getColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		OutFile << getColorName(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;

}

bool CSquare::belongsToFigure(Point P)
{
	return P.x >= (Center.x - 40) && P.x <= (Center.x + 40) && P.y >= (Center.y - 40) && P.y <= (Center.y + 40);
}

void CSquare::move(Point P1) {
	Center.x = P1.x;
	Center.y = P1.y;
}

void CSquare::PrintInfo(Output* pOut) const
{
	string Xstr = to_string(Center.x);
	string Ystr = to_string(Center.y);
	string IDstr = to_string(ID);
	pOut->PrintMessage("ID = " + IDstr + ' ' + "Side length = 80 " + "Center = (" + Xstr + ',' + Ystr + ')');
}

void CSquare::getCenter(int& x, int& y) const {
	x = Center.x;
	y = Center.y;
}

void CSquare::Load(ifstream& Infile)
{
	Selected = false;
	string DrwColor;
	string FilColor;

	Infile >> ID;
	Infile >> Center.x >> Center.y;
	Infile >> DrwColor >> FilColor;

	setDrwColorLoad(DrwColor);
	setFilColorLoad(FilColor);
}

string CSquare::GetType() const
{
	return "sqaure";
}