#include "StartScreen.h"

Bitmap *startScreen;

void StartScreen::init(int ix, int iy, int idx, int icols, int irows)
{
	x = ix;
	y = iy;
	dx = idx;

	width = startScreen->getWidth();
	height = startScreen->getHeight();

	ncols = icols;
	nrows = irows;

	currentCell = 0;
	setSpriteSheetDimensions(width, height);

	ref_x = ref_y = 0;
}

StartScreen::StartScreen(int ix, int iy, int idx, int icols, int irows, const char *file)
{
	startScreen = new Bitmap(file, true);
	this->init(ix, iy, idx, icols, irows);
}

void StartScreen::setSpriteSheetDimensions(int w, int h) 
{
	sheet_width = w;
	sheet_height = h;
	calculate_cells();
}

void StartScreen::calculate_cells() 
{	
	cellWidth = sheet_width / ncols;
	cellHeight = sheet_height / nrows;
}

void StartScreen::draw()
{
	int currentCol = currentCell % ncols;
	int currentRow = currentCell / ncols;
	int cx = cellWidth * currentCol;
	int cy = cellHeight * currentRow;

	startScreen->drawAt(x - ref_x, y - ref_y, cx, cy, cellWidth, cellHeight);
}


StartScreen::~StartScreen() 
{
	if (startScreen)
		delete  startScreen;
	
}
