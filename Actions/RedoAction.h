#include "Action.h"

class RedoAction : public Action
{
public:
	RedoAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual bool canBeRecorded();

};