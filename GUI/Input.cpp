#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

bool Input::GetButtonState(const button btMouse, int& x, int& y) const
{
	if (pWind->GetButtonState(btMouse, x, y) == BUTTON_DOWN)
		return true;
	else
		return false;
}

void Input::GetCurrentCoord(int& x, int& y) const
{
	pWind->GetMouseCoord(x, y);
}


string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				case ITM_SLIC: return SELECT_ITEM;
				case ITM_Circ: return DRAW_CIRC;
				case ITM_SQUARE: return DRAW_SQUARE;
				case ITM_TRIANGLE: return DRAW_TRIANGLE;
			    case ITM_RECT: return DRAW_RECT;
				case ITM_HEXA: return DRAW_HEXAGON;
				case ITM_CHANGE_FILLING_COLOR: return  CHANGE_FILLING_COLOR;
				case ITM_CHANGE_DRAWING_COLOR: return  CHANGE_DRAWING_COLOR;
				case ITM_BLACK: return  BLACK_COLOR;
				case ITM_YELLOW: return  YELLOW_COLOR;
				case ITM_ORANGE: return  ORANGE_COLOR;
				case ITM_RED: return  RED_COLOR;
				case ITM_GREEN: return  GREEN_COLOR;
				case ITM_BLUE: return  BLUE_COLOR;
				case ITM_MOVE: return  MOVE_ITEM;
				case ITM_DRAG: return  DRAG_ITEM;
				case ITM_DELETE_FIGURE: return  DELETE_ITEM;
				case ITM_UNDO: return  UNDO;
				case ITM_REDO: return  REDO;
				case ITM_DELETE_ALL: return  CLEAR;
				case ITM_STARTREC: return  START_RECORDING;
				case ITM_PLAYREC: return  PLAY_RECORDING;
				case ITM_STOPREC: return  STOP_RECORDING;
				case ITM_SAVEGRAPH: return  SAVE_DRAWING;
				case ITM_LOADGRAPH: return  LOAD_DRAWING;
				case ITM_TOGGLESOUND: return  TOGGLESOUND;
				case ITM_SWITCH: return  TO_PLAY;
				case ITM_EXIT: return  EXIT;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case PLAY_ITM_PICK_FIGURE_TYPE: return  PICK_FIGURE_TYPE;
			case PLAY_ITM_PICK_FIGURE_COLOR: return  PICK_FIGURE_COLOR;
			case PLAY_ITM_PICK_FIGURE_TYPE_COLOR: return  PICK_FIGURE_TYPE_COLOR;
			case PLAY_ITM_SWITCH: return  TO_DRAW;
			case PLAY_ITM_EXIT: return  EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
