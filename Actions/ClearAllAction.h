#include "Action.h"
class ClearAllAction : public Action
{
public:
	ClearAllAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
};
