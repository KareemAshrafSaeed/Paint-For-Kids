#include "CFigure.h"

CFigure::~CFigure() {
}
CFigure::CFigure() {
	related_actions = 0;
	Choosed = false;
	ID = -1;
	Selected = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	related_actions = 1;
	Choosed = false;
	ID = -1;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

void CFigure::setRelatedActionsCount(int count) {
	related_actions = count;
}
int CFigure::getRelatedActionsCount() const {
	return related_actions;
}

void CFigure::SetID(int id)
{
	ID = id;
}

int CFigure::getID() const {
	return ID;
}

color CFigure::GetColor() const
{
	if (FigGfxInfo.isFilled)
		return FigGfxInfo.FillClr;
	return WHITE;
}

string CFigure::getColorName(color col) {
	if (col == BLACK) return "black";
	if (col == YELLOW) return "yellow";
	if (col == ORANGE) return "orange";
	if (col == GREEN) return "green";
	if (col == BLUE) return "blue";
	return "NO FILL";
}

color CFigure::StringToColor(string S)
{
	if (S == "red")
		return RED;
	if (S == "yellow")
		return YELLOW;
	if (S == "green")
		return GREEN;
	if (S == "orange")
		return ORANGE;
	if (S == "black")
		return BLACK;
	return BLUE;
}

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}



void CFigure::setIsFilled( bool x) {
	FigGfxInfo.isFilled = x;
}

const color CFigure::getDrawClr() const {
	return FigGfxInfo.DrawClr;
}


const color CFigure::getFillClr() const {
	return FigGfxInfo.FillClr;
}

bool CFigure::IsFilled() const {
	return FigGfxInfo.isFilled;
}

void CFigure::SetChoosed(bool s)
{
	Choosed = s;
}
bool CFigure::IsChoosed() const
{
	return Choosed;
}


void CFigure::setDrwColorLoad(string DrwColor)
{
	FigGfxInfo.DrawClr = StringToColor(DrwColor);
}
void CFigure::setFilColorLoad(string FilColor)
{

	if (FilColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
	}
	FigGfxInfo.FillClr = StringToColor(FilColor);

}
