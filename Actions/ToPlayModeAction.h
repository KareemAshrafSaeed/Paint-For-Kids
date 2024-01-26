#ifndef ToPlayAction_H
#define ToPlayAction_H

#include"Action.h"
#include "..\Figures\CFigure.h"

class ToPlayModeAction :public Action
{
public:

	ToPlayModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);

};

#endif

