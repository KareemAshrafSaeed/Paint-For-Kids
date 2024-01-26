#include "Action.h"

class StartRecordingAction : public Action
{
public:
	StartRecordingAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);

};