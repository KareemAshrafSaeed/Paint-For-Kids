#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include <math.h> 
#include<windows.h>

#define PI 3.14159265

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	string getColorName(color col);
	color StringToColor(string S);

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearToolBar() const;	//Clears the tool bar
	void ClearDrawArea() const;	//Clears the drawing area

	bool toggleSound();
	void playSound(string sound_path);
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected = false) const;
	void DrawSquare(Point Center, GfxInfo SquareGfxInfo, bool selected) const;
	void DrawHex(Point Center, GfxInfo HexGfxInfo, bool selected = false) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TrianglefxInfo, bool selected) const;
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	color getCrntDrawColor() const;	//get current drwawing color
	bool getDrawFilledFigures() const;
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void setDrwColorLoad(string);
	void setFilColorLoad(string);

	
	~Output();
};

#endif