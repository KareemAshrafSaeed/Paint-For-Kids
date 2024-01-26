#include "Action.h"

class StopRecordingAction : public Action
{
public:
	StopRecordingAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);

};