#include"Action.h"
#include "..\Figures\CFigure.h"

class DragAction :public Action
{
private:
	Point TheOldCenter;
	Point TheNewCenter;
public:
	DragAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
};