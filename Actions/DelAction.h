#ifndef DEL_ACTION_H
#define DEL_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class DelAction : public Action
{
	bool success; // if the action is executed successfull then it will have undo / redo otherwise it will not be saved
	CFigure* deletedFigure; // save a copy from it just In case I wanted to undo the operation
public:
	DelAction(ApplicationManager* pApp);
	~DelAction();
	virtual void ReadActionParameters();

	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
	
};

#endif
