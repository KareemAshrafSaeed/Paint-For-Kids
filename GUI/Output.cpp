#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 42;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	UI.sound = true;
	UI.drawFilledFigures = false;

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	//Clear tool bar by drawing a filled white rectangle
	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	ClearToolBar();

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SLIC] = "images\\MenuItems\\Menu_SLIC.jpg";
	MenuItemImages[ITM_Circ] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_SQUARE.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_TRIANGLE.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Menu_HEXA.jpg";
	MenuItemImages[ITM_CHANGE_FILLING_COLOR] = "images\\MenuItems\\Menu_FILLING.jpg";
	MenuItemImages[ITM_CHANGE_DRAWING_COLOR] = "images\\MenuItems\\Menu_DROWING.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_BLACK.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_YELLOW.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_ORANGE.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_RED.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_GREEN.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_BLUE.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_MOVE.jpg";
	MenuItemImages[ITM_DRAG] = "images\\MenuItems\\Menu_DRAG.jpg";
	MenuItemImages[ITM_DELETE_FIGURE] = "images\\MenuItems\\Menu_DELETE_FIGURE.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_UNDO.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_REDO.jpg";
	MenuItemImages[ITM_DELETE_ALL] = "images\\MenuItems\\Menu_DELETE_ALL.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\Menu_STARTREC.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\Menu_PLAYREC.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\Menu_STOPREC.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\Menu_SAVEGRAPH.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\Menu_LOADGRAPH.jpg";
	MenuItemImages[ITM_TOGGLESOUND] = "images\\MenuItems\\Menu_toggle_sound.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\Menu_switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

bool Output::toggleSound() {
	UI.sound = !UI.sound;
	return UI.sound;
}

void Output::playSound(string filename) {
	if(UI.sound) PlaySound(("sounds\\"+ filename).c_str(), NULL, SND_ASYNC);
}


string Output::getColorName(color col) {
	if (col == BLACK) return "black";
	if (col == YELLOW) return "yellow";
	if (col == ORANGE) return "orange";
	if (col == GREEN) return "green";
	if (col == BLUE) return "blue";
	return "NO FILL";
}

color Output::StringToColor(string S)
{
	if (S == "red")
		return RED;
	if (S == "yellow")
		return YELLOW;
	if (S == "green")
		return GREEN;
	if (S == "orange")
		return ORANGE;
	if (S == "black")
		return BLACK;
	return BLUE;
}

void Output::setDrwColorLoad(string DrwColor)
{
	UI.DrawColor = StringToColor(DrwColor);
}
void Output::setFilColorLoad(string FilColor)
{

	if (FilColor == "NO_FILL")
	{
		UI.drawFilledFigures = false;
	}
	else {
		UI.drawFilledFigures = true;
	}
	UI.FillColor = StringToColor(FilColor);

}

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar();

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PLAY_ITM_PICK_FIGURE_TYPE] = "images\\MenuItems\\Menu_Figure_type.jpg";
	MenuItemImages[PLAY_ITM_PICK_FIGURE_COLOR] = "images\\MenuItems\\Menu_Figure_color.jpg";
	MenuItemImages[PLAY_ITM_PICK_FIGURE_TYPE_COLOR] = "images\\MenuItems\\Menu_Figure_type_color.jpg";
	MenuItemImages[PLAY_ITM_SWITCH] = "images\\MenuItems\\Menu_switch.jpg";
	MenuItemImages[PLAY_ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);



}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

bool Output::getDrawFilledFigures() const {
	return UI.drawFilledFigures;
}

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}



void Output::DrawHex(Point Center, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int side_length = 30.00 * sqrt(3);
	int x_coord[6];
	int y_coord[6];
	for (int i = 0; i < 6; i++)
	{
		x_coord[i] = Center.x + side_length * cos(i * (PI / 3.00));
		y_coord[i] = Center.y + side_length * sin(i * (PI / 3.00));
	}
	pWind->DrawPolygon(x_coord, y_coord, 6, style);
}


void Output::DrawSquare(Point Center, GfxInfo SquareGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int side_length = 80;
	int x1 = Center.x - 0.5 * side_length;
	int x2 = Center.x + 0.5 * side_length;
	int y1 = Center.y - 0.5 * side_length;
	int y2 = Center.y + 0.5 * side_length;
	pWind->DrawRectangle(x1,y1,x2,y2,style);
}


void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	double radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	pWind->DrawCircle(P1.x, P1.y, radius, style);
}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

