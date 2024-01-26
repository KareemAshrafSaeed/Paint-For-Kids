#include"Action.h"
#include "..\Figures\CFigure.h"

class PickColor :public Action
{
	Point P;
	int Correct;
	int Wrong;
	string NameColor;
	color PlayingColor;

public:

	PickColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	void printScore();

};

