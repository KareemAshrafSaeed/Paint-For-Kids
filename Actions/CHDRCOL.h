#ifndef CHDRCOL_H
#define CHDRCOL_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class CHDRCOL : public Action
{
	color c;
	color old_color;
	color ui_old_color;
	CFigure * ChangedFigure;
	bool success; // if the action is executed successfull then it will have undo / redo otherwise it will not be saved
public:
	CHDRCOL(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	void getcolor(ActionType ActType);
	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};

#endif

