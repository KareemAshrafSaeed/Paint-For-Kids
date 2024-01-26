#ifndef CHFILLCOL_H
#define CHFILLCOL_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class CHFILLCOL : public Action
{
	color c;
	color old_color;
	bool old_filled;
	bool ui_old_filled;
	color ui_old_color;
	CFigure* ChangedFigure;
	bool success; // if the action is executed successfull then it will have undo / redo otherwise it will not be saved
public:
	CHFILLCOL(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	void getcolor(ActionType ActType);
	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};

#endif
#pragma once
