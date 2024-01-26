#include"CCircle.h"

CCircle::CCircle() :CFigure() {}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
	radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(Center, PointOnCircle, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "Circ" << "\t"
		<< ID << "\t"
		<< Center.x << "\t"
		<< Center.y << "\t"
		<< PointOnCircle.x << "\t"
		<< PointOnCircle.y << "\t"
		<< getColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		OutFile << getColorName(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

bool CCircle::belongsToFigure(Point P)
{
	return sqrt(pow((Center.x - P.x), 2) + pow((Center.y - P.y), 2)) <= radius;
}

void CCircle::getCenter(int& x, int& y) const {
	x = Center.x;
	y = Center.y;
}


void CCircle::move(Point P)
{
	double dx = P.x - Center.x;
	double dy = P.y - Center.y;
	Center.x = P.x;
	Center.y = P.y;
	PointOnCircle.x += dx;
	PointOnCircle.y += dy;
}

void CCircle::PrintInfo(Output* pOut) const
{
	string IDstr = to_string(ID);
	string XCstr = to_string(Center.x);
	string YCstr = to_string(Center.y);
	string XPoC = to_string(PointOnCircle.x);
	string YPoC = to_string(PointOnCircle.y);
	string RadiusStr = to_string(radius);
	pOut->PrintMessage("ID = " + IDstr + ' ' + "Center = (" + XCstr + ',' + YCstr + ") " + "Radius = " + RadiusStr);

}

void CCircle::Load(ifstream& Infile)
{
	Selected = false;
	string DrwColor;
	string FilColor;

	Infile >> ID;
	Infile >> Center.x >> Center.y;
	Infile >> PointOnCircle.x >> PointOnCircle.y;
	Infile >> DrwColor >> FilColor;


	radius = sqrt(pow((Center.x - PointOnCircle.x), 2) + pow((Center.y - PointOnCircle.y), 2));
	setDrwColorLoad(DrwColor);
	setFilColorLoad(FilColor);


}

string CCircle::GetType() const
{
	return "circle";
}

