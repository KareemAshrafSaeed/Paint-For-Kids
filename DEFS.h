#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SELECT_ITEM,
	BLACK_COLOR,
	YELLOW_COLOR,
	ORANGE_COLOR,
	RED_COLOR,
	GREEN_COLOR,
	BLUE_COLOR,
	MOVE_ITEM,
	DRAG_ITEM,
	DELETE_ITEM,
	UNDO,
	REDO,
	CLEAR,
	START_RECORDING,
	PLAY_RECORDING,
	STOP_RECORDING,
	SAVE_DRAWING,
	LOAD_DRAWING,
	TOGGLESOUND,
	DRAW_RECT,
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_HEXAGON,
	CHANGE_DRAWING_COLOR,
	CHANGE_FILLING_COLOR,
	DRAW_CIRC,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	PICK_FIGURE_TYPE,
	PICK_FIGURE_COLOR,
	PICK_FIGURE_TYPE_COLOR,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif