#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"
class AddCircAction : public Action
{
private:
	Point P1, P2;
	GfxInfo CircGfxInfo;
	CFigure * AddedCircle;
public:
	AddCircAction(ApplicationManager* pApp);
	virtual ~AddCircAction();
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};
#endif
