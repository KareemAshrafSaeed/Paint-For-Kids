#include"CHexagon.h"

CHex::CHex() :CFigure() {}

CHex::CHex(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}

void CHex::Draw(Output* pOut) const
{
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

void CHex::Save(ofstream& OutFile)
{
	OutFile << "HEXAGON" << "\t"
		<< ID << "\t"
		<< Center.x << "\t"
		<< Center.y << "\t"
		<< getColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		OutFile << getColorName(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;

}

bool CHex::belongsToFigure(Point P)
{
	double InnerR = 45;
	double OutterR = 30 * sqrt(3);
	double L = sqrt(pow((Center.x - P.x), 2) + pow((Center.y - P.y), 2));
	if (L <= InnerR)
		return true;
	if (L < (InnerR + (OutterR - InnerR)) * 0.1) return true;
	if (L >= OutterR)
		return false;
}


void CHex::move(Point P1) {
	Center.x = P1.x;
	Center.y = P1.y;
}

void CHex::PrintInfo(Output* pOut) const
{
	double sideLength = 30 * sqrt(3);
	string IDstr = to_string(ID);
	string SideLengthStr = to_string(sideLength);
	string X = to_string(Center.x);
	string Y = to_string(Center.y);
	pOut->PrintMessage("ID = " + IDstr + ' ' + "Side length = " + SideLengthStr + ' ' + "Center = (" + X + ',' + Y + ')');
}

void CHex::getCenter(int& x, int& y) const {
	x = Center.x;
	y = Center.y;
}

void CHex::Load(ifstream& Infile)
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

string CHex::GetType() const
{
	return "hexagon";
}