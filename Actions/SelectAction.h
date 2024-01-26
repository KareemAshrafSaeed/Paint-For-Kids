#include"Action.h"

class SelectAction : public Action
{
private:
	Point PClicked;
public:
	SelectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual bool canBeRecorded();
};