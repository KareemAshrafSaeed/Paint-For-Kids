#include"CTriangle.h"

CTriangle::CTriangle():CFigure(){}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
	center_x = (P1.x + P2.x + P3.x) / 3;
	center_y = (P1.y + P2.y + P3.y) / 3;
	L1 = sqrt(pow((Vertix2.x - Vertix3.x), 2) + pow((Vertix2.y - Vertix3.y), 2));
	L2 = sqrt(pow((Vertix1.x - Vertix3.x), 2) + pow((Vertix1.y - Vertix3.y), 2));
	L3 = sqrt(pow((Vertix1.x - Vertix2.x), 2) + pow((Vertix1.y - Vertix2.y), 2));
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANGLE" << "\t"
		<< ID << "\t"
		<< Vertix1.x << "\t"
		<< Vertix1.y << "\t"
		<< Vertix2.x << "\t"
		<< Vertix2.y << "\t"
		<< Vertix3.x << "\t"
		<< Vertix3.y << "\t"
		<< getColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		OutFile << getColorName(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

float CTriangle::area(Point p1, Point p2, Point p3) const // gets the area using three points
{
	return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

bool CTriangle::belongsToFigure(Point P)
{

	float A = area(Vertix1, Vertix2, Vertix3);

	float A1 = area(P, Vertix2, Vertix3);

	float A2 = area(Vertix1, P, Vertix3);

	float A3 = area(Vertix1, Vertix2, P);

	return (A == A1 + A2 + A3);
}

void CTriangle::move(Point P1) {
	float dx = P1.x - center_x;
	float dy = P1.y - center_y;
	Vertix1.x += dx;
	Vertix1.y += dy;
	Vertix2.x += dx;
	Vertix2.y += dy;
	Vertix3.x += dx;
	Vertix3.y += dy;
	center_x = P1.x;
	center_y = P1.y;
}

void CTriangle::PrintInfo(Output* pOut) const
{
	string IDstr = to_string(ID);
	string L1str = to_string(L1);
	string L2str = to_string(L2);
	string L3str = to_string(L3);

	string X1 = to_string(Vertix1.x);
	string Y1 = to_string(Vertix1.y);

	string X2 = to_string(Vertix2.x);
	string Y2 = to_string(Vertix2.y);

	string X3 = to_string(Vertix3.x);
	string Y3 = to_string(Vertix3.y);

	pOut->PrintMessage("ID = " + IDstr + ' ' + "L1 = " + L1str + " L2 = " + L2str + " L3 = " + L3str); // verixInfo may be added
}


void CTriangle::getCenter(int& x, int& y) const {
	x = center_x;
	y = center_y;
}

void CTriangle::Load(ifstream& Infile)
{
	Selected = false;
	string DrwColor;
	string FilColor;

	Infile >> ID;
	Infile >> Vertix1.x >> Vertix1.y;
	Infile >> Vertix2.x >> Vertix2.y;
	Infile >> Vertix3.x >> Vertix3.y;
	Infile >> DrwColor >> FilColor;

	center_x = (Vertix1.x + Vertix2.x + Vertix3.x) / 3;
	center_y = (Vertix1.y + Vertix2.y + Vertix3.y) / 3;
	L1 = sqrt(pow((Vertix2.x - Vertix3.x), 2) + pow((Vertix2.y - Vertix3.y), 2));
	L2 = sqrt(pow((Vertix1.x - Vertix3.x), 2) + pow((Vertix1.y - Vertix3.y), 2));
	L3 = sqrt(pow((Vertix1.x - Vertix2.x), 2) + pow((Vertix1.y - Vertix2.y), 2));

	setDrwColorLoad(DrwColor);
	setFilColorLoad(FilColor);
}
string CTriangle::GetType() const
{
	return "triangle";
}