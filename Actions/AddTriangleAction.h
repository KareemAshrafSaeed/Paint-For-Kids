#ifndef ADD_TRIANGLE_H
#define ADD_TRIANGLE_H

#include"Action.h"
#include "..\Figures\CTriangle.h"

class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3;
	GfxInfo TriangleGfxInfo;
	CTriangle* AdddedTriangle;
public:
	AddTriangleAction(ApplicationManager* pApp);
	~AddTriangleAction();
	virtual void ReadActionParameters();
	virtual void Execute(bool read_params = true);
	virtual void Undo();
	virtual void Redo();
	virtual bool canBeRecorded();
};

#endif