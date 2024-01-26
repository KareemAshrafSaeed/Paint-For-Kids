#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool Choosed;
	int related_actions;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	virtual ~CFigure();
	void setRelatedActionsCount(int count);
	int getRelatedActionsCount() const;
	void SetID(int id);
	int getID() const;
	string getColorName(color col);
	color StringToColor(string S);
	virtual string GetType() const = 0;
	color GetColor() const;
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	const color getDrawClr() const;
	const color getFillClr() const;
	bool IsFilled() const;
	void setIsFilled(bool x);
	bool IsChoosed() const; // returns true if the figure is choosed in play mode
	void SetChoosed(bool s = true); // sets choosed 
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual bool belongsToFigure(Point P) = 0; // returns true if the point given is inside the figure area

	virtual void move(Point P) = 0;
	virtual void getCenter(int& x, int& y) const = 0;
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters from the file to the current object

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
	void setDrwColorLoad(string);
	void setFilColorLoad(string);
};

#endif