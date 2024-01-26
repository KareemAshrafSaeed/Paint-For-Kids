#include "Action.h"

class PlayRecordingAction : public Action
{
public:
	PlayRecordingAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);

};