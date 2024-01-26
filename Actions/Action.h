#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

#include "..\Figures\CFigure.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor
	virtual ~Action();
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute(bool read_params = true) = 0;
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();

};

#endif