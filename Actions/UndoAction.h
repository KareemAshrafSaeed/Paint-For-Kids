#include "Action.h"

class UndoAction : public Action
{
public:
	UndoAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual bool canBeRecorded();
};