#include "Action.h"

class ToggleSoundAction : public Action
{
public:
	ToggleSoundAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);

};