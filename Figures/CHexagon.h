#ifndef CHEX_H
#define CHEX_H

#include"CFigure.h"

class CHex :public CFigure
{
private:
	Point Center;
public:
	CHex(Point, GfxInfo FigureGfxInfo);
	CHex();
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