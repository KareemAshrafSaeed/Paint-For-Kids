#include "CRectangle.h"

CRectangle::CRectangle() :CFigure() {}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	center_x = (P1.x + P2.x) / 2;
	center_y = (P1.y + P2.y) / 2;
	Height = abs(Corner1.y - Corner2.y);
	Width = abs(Corner1.x - Corner2.x);
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


void CRectangle::Save(ofstream& OutFile)
{

	OutFile << "RECT" << "\t"
		<< ID << "\t"
		<< Corner1.x << "\t"
		<< Corner1.y << "\t"
		<< Corner2.x << "\t"
		<< Corner2.y << "\t"
		<< getColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		OutFile << getColorName(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;

}

bool CRectangle::belongsToFigure(Point P)
{
	bool expression1 = false;
	bool expression2 = false;
	if (Corner1.x < Corner2.x) 
		expression1 = P.x >= Corner1.x && P.x <= Corner2.x;
	else
		expression1 = P.x >= Corner2.x && P.x <= Corner1.x;
	if (Corner1.y < Corner2.y)
		expression2 = P.y >= Corner1.y && P.y <= Corner2.y;
	else
		expression2 = P.y >= Corner2.y && P.y <= Corner1.y;
	return  expression1 && expression2;
}


void CRectangle::move(Point P1) {
	float dx = P1.x - center_x;
	float dy = P1.y - center_y;
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
	center_x = P1.x;
	center_y = P1.y;
}

void CRectangle::PrintInfo(Output* pOut) const
{
	string IDstr = to_string(ID);

	string HeightStr = to_string(Height);
	string WidthStr = to_string(Width);
	string Xstr = to_string(center_x);
	string Ystr = to_string(center_y);
	pOut->PrintMessage("ID = " + IDstr + ' ' + "Height = " + HeightStr + ' ' + "Width = " + WidthStr + ' ' + "Center = " + '(' + Xstr + ',' + Ystr + ')');
}

void CRectangle::getCenter(int& x, int& y) const {
	x = center_x;
	y = center_y;
}


void CRectangle::Load(ifstream& Infile)
{
	Selected = false;
	string DrwColor;
	string FilColor;

	Infile >> ID;
	Infile >> Corner1.x >> Corner1.y;
	Infile >> Corner2.x >> Corner2.y;
	Infile >> DrwColor >> FilColor;

	Height = abs(Corner1.y - Corner2.y);
	Width = abs(Corner1.x - Corner2.x);
	center_x = (Corner1.x + Corner2.x) / 2;
	center_y = (Corner1.y + Corner2.y) / 2;

	setDrwColorLoad(DrwColor);
	setFilColorLoad(FilColor);
}

string CRectangle::GetType() const
{
	return "Rectangle";
}