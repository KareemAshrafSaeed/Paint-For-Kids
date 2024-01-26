#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H

#include "Action.h"
#include<iostream>

class LoadAction : public Action
{
private:
	string filename;
public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool read_params = true);

};

#endif
