#include"Action.h"
#include "..\Figures\CFigure.h"

class Pick_Type_Color :public Action
{
	Point P;
	int Correct;
	int Wrong;
	string Fig;
	string NameColor;
	color PlayingColor;
public:

	Pick_Type_Color(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	void printScore();
};
