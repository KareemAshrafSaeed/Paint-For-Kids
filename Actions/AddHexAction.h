#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include"Action.h"
#include "..\Figures\CHexagon.h"
class AddHexAction : public Action
{
private:
	Point P;
	GfxInfo HexGfxInfo;
	CHex* AddedHexagon;
public:
	AddHexAction(ApplicationManager* pApp);
	~AddHexAction();
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};
#endif