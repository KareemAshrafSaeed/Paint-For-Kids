#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SLIC,
	ITM_Circ,
	ITM_SQUARE,
	ITM_TRIANGLE,
	ITM_RECT,
	ITM_HEXA,
	ITM_CHANGE_FILLING_COLOR,
	ITM_CHANGE_DRAWING_COLOR,
	ITM_BLACK,
	ITM_YELLOW,
	ITM_ORANGE,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_MOVE,
	ITM_DRAG,
	ITM_DELETE_FIGURE,
	ITM_UNDO,
	ITM_REDO,
	ITM_DELETE_ALL,
	ITM_STARTREC,
	ITM_PLAYREC,
	ITM_STOPREC,
	ITM_SAVEGRAPH,
	ITM_LOADGRAPH,
	ITM_TOGGLESOUND,
	ITM_SWITCH,
	ITM_EXIT,
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	PLAY_ITM_PICK_FIGURE_TYPE,		
	PLAY_ITM_PICK_FIGURE_COLOR,		
	PLAY_ITM_PICK_FIGURE_TYPE_COLOR,		
	PLAY_ITM_SWITCH,		
	PLAY_ITM_EXIT,  //Exit item
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

	bool drawFilledFigures;
	bool sound; // turns sound on / off
	
}UI;	//create a global object UI

#endif