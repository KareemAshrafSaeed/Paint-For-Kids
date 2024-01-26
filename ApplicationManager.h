#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxUndoCount = 5 , max_recorded_operations = 20};	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int UndoneActions;		//Actual number of undone actions
	int LastActionsCount;		//Actual number of last actions
	int recordedOperationsCount;
	int AllActionsCount;
	bool recording;
	Action* RecordedOperations[max_recorded_operations];
	Action* UndoList[MaxUndoCount];
	Action* LastActions[MaxUndoCount];
	Action* AllActions[200]; // saving all actions here so I can delete them on clear all
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:	
	ApplicationManager();
	~ApplicationManager();

	void SaveAll(ofstream& file);

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	void setSelectedFigure(CFigure* f);
	CFigure* getSelectedFigure();
	//actions management 
	void saveAction(Action* a);
	// undo / redo functions
	void RemoveFigureByID(int id);
	void saveUndoAction(Action* a);
	void clearUndoList();
	bool UndoLastAction();
	bool RedoLastAction();

	// recording functions
	bool startRecording();
	bool stopRecording();
	void recordAction(Action* a);
	bool playRecordedActions();

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void ClearAll(bool clear_recorded_actions = false);
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing windo

	// play mode functions
	void ShowAll();
	string randomFigure(int& Count)const; // it chooses the RandomFig 
	string randomColor(int& Count, color& Color) const; //Gets The random color
	string randomFigureColor(int& Count, color& Color, string& NameColor) const; // it chooses the RandomFig and color
};

#endif