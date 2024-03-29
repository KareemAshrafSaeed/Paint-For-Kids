#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"
#include "..\Figures\CRectangle.h"
//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CRectangle* AddedRectangle;
public:
	AddRectAction(ApplicationManager *pApp);
	~AddRectAction();
	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute(bool read_params = true) ;
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};

#endif