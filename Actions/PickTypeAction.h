#ifndef TYPE_H
#define TYPE_H

#include"Action.h"
#include "..\Figures\CFigure.h"

class TYPE :public Action
{
	Point P;
	int Correct;
	int Wrong;
	string Fig;
public:

	TYPE(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	void printScore();
};

#endif
#pragma once
