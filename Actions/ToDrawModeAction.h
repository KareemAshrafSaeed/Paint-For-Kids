#ifndef ToDrawAction_H
#define ToDrawAction_H

#include"Action.h"
#include "..\Figures\CFigure.h"

class ToDrawModeAction :public Action
{
public:

	ToDrawModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);

};

#endif
