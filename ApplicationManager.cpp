#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\SaveAllAction.h"
#include "Actions\UndoAction.h"
#include "Actions\RedoAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\SelectAction.h"
#include "Actions\StartRecordingAction.h"
#include "Actions\StopRecordingAction.h"
#include "Actions\PlayRecordingAction.h"
#include "Actions\CHDRCOL.h"
#include "Actions\CHFILLCOL.h"
#include "Actions/DelAction.h"
#include "Actions/MoveAction.h"
#include "Actions/LoadAction.h"
#include "Actions/ToggleSoundAction.h"
#include "Actions/PickTypeAction.h"
#include "Actions/PickColorAction.h"
#include "Actions/Pick_Type_ColorAction.h"
#include "Actions/ToDrawModeAction.h"
#include "Actions/ToPlayModeAction.h"
#include "Actions/DragAction.h"
#include <windows.h>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	UndoneActions = 0;
	LastActionsCount = 0;
	recordedOperationsCount = 0;
	AllActionsCount = 0;

	recording = false;

	
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL	
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for (int i = 0; i < 200; i++)
		AllActions[i] = NULL;
	for (int i = 0; i < MaxUndoCount; i++) {
		UndoList[i] = NULL;
		LastActions[i] = NULL;
	}

	for (int i = 0; i < max_recorded_operations; i++)
		RecordedOperations[i] = NULL;
		
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case DRAW_TRIANGLE:
			pAct = new AddTriangleAction(this);
			break;

		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			break;


		case DRAW_HEXAGON:
			pAct = new AddHexAction(this);
			break;

		case SELECT_ITEM:
			pAct = new SelectAction(this);
			break;


		case MOVE_ITEM:
			pAct = new MoveAction(this);
			break;

		case DRAG_ITEM:
			pAct = new DragAction(this);
			break;
			

		case DELETE_ITEM:
			pAct = new DelAction(this);
			break;


		case UNDO:
			pAct = new UndoAction(this);
			break;

		case REDO:
			pAct = new RedoAction(this);
			break;

		case CLEAR:
			pAct = new ClearAllAction(this);
			break;


		case START_RECORDING:
			pAct = new StartRecordingAction(this);
			break;

		case PLAY_RECORDING:
			pAct = new PlayRecordingAction(this);
			break;

		case STOP_RECORDING:
			pAct = new StopRecordingAction(this);
			break;
		case SAVE_DRAWING:
			pAct = new SaveAllAction(this);
			break;

		case LOAD_DRAWING:
			pAct = new LoadAction(this);
			break;
		case CHANGE_FILLING_COLOR:
			pAct = new CHFILLCOL(this);
			break;
		case CHANGE_DRAWING_COLOR:
			pAct = new CHDRCOL(this);
			break;
		case TOGGLESOUND:
			pAct = new ToggleSoundAction(this);
			break;
			

		case PICK_FIGURE_TYPE:
			pAct = new TYPE(this);
			break;

		case PICK_FIGURE_COLOR:
			pAct = new PickColor(this);
			break;

		case PICK_FIGURE_TYPE_COLOR:
			pAct = new Pick_Type_Color(this);
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pAct = new ToDrawModeAction(this);
			break;

		case TO_PLAY:
			pAct = new ToPlayModeAction(this);
			break;

		case EXIT:
			ClearAll(true);

			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if (pAct != NULL)
	{
		if (recording && pAct->canBeRecorded() && recordedOperationsCount == max_recorded_operations) {
			pOut->PrintMessage("can't do more actions than that in recording mode");
			pAct = NULL;
			return;
		}
		pAct->Execute();

		if (pAct->canBeRecorded() && recording) {
			recordAction(pAct);
		}
		saveAction(pAct); // saving the action in AllActions array to delete it on clear All
		pAct = NULL;
	}
}


bool ApplicationManager::playRecordedActions() {
	if (recordedOperationsCount == 0) return false;
	ClearAll();
	UpdateInterface();
	Sleep(1000);
	for (int i = 0; i < recordedOperationsCount; i++)
	{
		RecordedOperations[i]->Execute(0);
		UpdateInterface();
		Sleep(1000);
	}
	return true;
}

bool ApplicationManager::startRecording() {
	if (FigCount != 0) return false;
	recording = true;
	return true;
}

bool ApplicationManager::stopRecording() {
	if (recording != true) return false;
	recording = false;
	return true;
}

void ApplicationManager::setSelectedFigure(CFigure* f) {
	if (SelectedFig != NULL) SelectedFig->SetSelected(false);
	if (f != NULL) f->SetSelected(true);
	SelectedFig = f;
}

CFigure* ApplicationManager::getSelectedFigure() {
	return SelectedFig;
}
void ApplicationManager::saveAction(Action* a) {
		AllActions[AllActionsCount++] = a;

}
void ApplicationManager::saveUndoAction(Action* a) {
	if (LastActionsCount == MaxUndoCount) { // checks if maximum number of undo is reached
		LastActions[0] = NULL; 
		for (int i = 0; i < (MaxUndoCount - 1); i++) {
			LastActions[i] = LastActions[i + 1]; // moving all the pointers one step backward
		}
		LastActions[MaxUndoCount - 1] = a; // setting the last one to the last operation I want to save it
	}
	else {
		LastActions[LastActionsCount++] = a; // otherwise just save
	}

}

void ApplicationManager::recordAction(Action* a) {
	RecordedOperations[recordedOperationsCount++] = a;
}

void ApplicationManager::clearUndoList() {
	UndoneActions = 0;
}

bool ApplicationManager::UndoLastAction() {

	if (LastActionsCount == 0) return false;

	LastActions[--LastActionsCount]->Undo(); // calling undo method on the last action

	UndoList[UndoneActions++] = LastActions[LastActionsCount]; // moving the action to the undone list to save it just in case the user wanted to redo that action again

	LastActions[LastActionsCount] = NULL; // setting the last action to null but not deleting the action as it will be used if the user wants to redo the action

	return true;
}

bool ApplicationManager::RedoLastAction() { // same logic as undo but in reverse way

	if (UndoneActions == 0) return false;

	UndoList[--UndoneActions]->Redo();

	LastActions[LastActionsCount++] = UndoList[UndoneActions];

	UndoList[UndoneActions] = NULL;

	return true;
}

void ApplicationManager::RemoveFigureByID(int id) {
	FigList[id]->SetID(-1); //set id to negative as it's not related to figlist now so I can check for that and delete it in undoable actions
	if (FigCount != 1) {
		FigList[id] = FigList[--FigCount]; // replace this place with the last one
		FigList[id]->SetID(id); // updates the id of last one with the new id
		FigList[FigCount] = NULL; // sets last place to null
	}
	else {
		FigList[--FigCount] = NULL;
	}
	
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount] = pFig;	
	pFig->SetID(FigCount++);
}

void ApplicationManager::SaveAll(ofstream& file)
{
	file << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(file);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure * ApplicationManager::GetFigure(int x, int y) const
{
	Point P1;
	P1.x = x;
	P1.y = y;
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->belongsToFigure(P1)) return FigList[i];
	}

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if (!FigList[i]->IsChoosed())
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::ClearAll(bool clear_recorded_actions) {
	if (clear_recorded_actions) {
		for (int i = 0; i < AllActionsCount; i++)
		{
				delete AllActions[i];
				AllActions[i] = NULL;
		}
		recordedOperationsCount = 0;
		AllActionsCount = 0;
	}
	for (int i = 0; i < FigCount; i++) delete FigList[i];
	FigCount = 0;
	UndoneActions = 0;
	LastActionsCount = 0;
	UI.DrawColor = BLUE;
	UI.drawFilledFigures = false;
}

void ApplicationManager::ShowAll() {
	for (int i = 0; i < FigCount; i++)
		FigList[i]->SetChoosed(false);
}

string ApplicationManager::randomFigure(int& Count)const
{
	Count = 0;
	int Rand;
	string Figure;

	if (FigCount != 0)
	{
		if (FigCount != 1)
		{
			//Randomly choose The Figure
			Rand = rand() % FigCount;
			Figure = FigList[Rand]->GetType();
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[Rand]->GetType() == FigList[i]->GetType())
				{
					Count++;
				}
			}
		}
		else
		{
			Figure = FigList[0]->GetType();
			Count = 1;
		}
		return Figure;
	}
	return "Empty";
}

string ApplicationManager::randomColor(int& Count, color& Color) const
{
	Count = 0;
	int Rand;
	string NameColor;

	if (FigCount != 0)
	{
		//Check if There are any Figure That have a Filling Color
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->IsFilled())
				break;
			else if (i == FigCount - 1)
				return "No_Fill";
		}


		//Randomly choose The Figure
		if (FigCount != 1)
		{
			do {
				Rand = rand() % FigCount;
			} while (!FigList[Rand]->IsFilled());

			Color = FigList[Rand]->GetColor();
			NameColor = FigList[Rand]->getColorName(Color);
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[Rand]->GetColor() == FigList[i]->GetColor())
				{
					Count++;
				}
			}
		}
		else
		{
			Color = FigList[0]->GetColor();
			NameColor = FigList[0]->getColorName(Color);
			Count = 1;
		}
		return NameColor;
	}
	return "No_Fill";
}


string ApplicationManager::randomFigureColor(int& Count, color& Color, string& NameColor) const
{

	if (FigCount != 0)
	{
		Count = 0;
		int Rand;
		string Figure;

		//Check if There are any Figure That have a Filling Color 
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i]->IsFilled())
				break;
			else if (i == FigCount - 1)
				return "Empty";
		}

		//Randomly choose The Figure
		if (FigCount != 1)
		{
			do {
				Rand = rand() % FigCount;
			} while (!FigList[Rand]->IsFilled());

			Color = FigList[Rand]->GetColor();
			Figure = FigList[Rand]->GetType();
			NameColor = FigList[0]->getColorName(Color);
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[Rand]->GetType() == FigList[i]->GetType() && FigList[Rand]->GetColor() == FigList[i]->GetColor())
				{
					Count++;
				}
			}
		}
		else
		{
			Color = FigList[0]->GetColor();
			Figure = FigList[0]->GetType();
			NameColor = FigList[0]->getColorName(Color);
			Count = 1;
		}
		return Figure;
	}
	return "Empty";
}

//Destructor
ApplicationManager::~ApplicationManager()
{
	ClearAll(true);
	delete pIn;
	delete pOut;
	
}


