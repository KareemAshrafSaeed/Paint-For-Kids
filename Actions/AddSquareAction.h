#ifndef ADD_SQUARE_H
#define ADD_SQUARE_H

#include "Action.h"
#include "..\Figures\CSquare.h"

class AddSquareAction : public Action
{
private:
	Point P;
	GfxInfo SquareGfxInfo;
	CSquare* AddedSquare;
public:
	AddSquareAction(ApplicationManager* pApp);
	~AddSquareAction();
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};
#endif