#ifndef CSQUARE_H
#define CSQUARE_H

#include"CFigure.h"

class CSquare :public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
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