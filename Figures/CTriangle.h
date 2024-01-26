#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include"CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Vertix1;
	Point Vertix2;
	Point Vertix3;
	float center_x;
	float center_y;
	double L1;
	double L2;
	double L3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void getCenter(int& x, int& y) const;
	float area(Point p1, Point p2, Point p3) const;
	virtual bool belongsToFigure(Point P);
	virtual void move(Point P);
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetType() const;
};

#endif