#ifndef SAVE_ALL_ACTION_H
#define SAVE_ALL_ACTION_H

#include "Action.h"

class SaveAllAction : public Action
{
private:
	string filename;
public:
	SaveAllAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool read_params= true);

};

#endif