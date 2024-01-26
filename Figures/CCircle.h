#ifndef CCirc_H
#define CCirc_H

#include"CFigure.h"

class CCircle :public CFigure
{
private:
	Point Center;
	Point PointOnCircle;
	double radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual bool belongsToFigure(Point P);
	virtual void getCenter(int& x, int& y) const;
	virtual void move(Point P);
	virtual void PrintInfo(Output* pOut) const;
	virtual void Load(ifstream& Infile);
	virtual string GetType() const;

};
#endif