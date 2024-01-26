#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	float center_x;
	float center_y;
	int Height;
	int Width;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual bool belongsToFigure(Point P);
	virtual void getCenter(int& x, int& y) const;
	virtual void move(Point P);
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetType() const;
};
#endif