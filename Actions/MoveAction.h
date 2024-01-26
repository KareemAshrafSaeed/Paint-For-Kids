#include"Action.h"
#include "..\Figures\CFigure.h"
class MoveAction : public Action
{
private:
	bool success; // if the action is executed successfully then it will have undo / redo otherwise it will not be saved
	Point thenewcenter;
	Point theoldcenter;
	CFigure* MovedFigure;
public:
	MoveAction(ApplicationManager* pApp );
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};