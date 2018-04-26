#include "BackgroundImage.h"
#include "Bitmap.h"

Bitmap *background1;
Bitmap *background2;

void BackgroundImage::init(int ix, int iy, int idx, int icols, int irows)
{
	x = ix;
	y = iy;
	dx = idx;

	width = background1->getWidth();
	height = background1->getHeight();

	width = background2->getWidth();
	height = background2->getHeight();

	ncols = icols;
	nrows = irows;

	currentCell = 0;
	setSpriteSheetDimensions(width, height);

	ref_x = ref_y = 0;
}

BackgroundImage::BackgroundImage(int ix, int iy, int idx, int icols, int irows,  const char *file)
{
	background1 = new Bitmap(file, true);
	background2 = new Bitmap(file, true);

	this->init(ix, iy, idx, icols, irows);
}

void BackgroundImage::setSpriteSheetDimensions(int w, int h) 
{
	sheet_width = w;
	sheet_height = h;
	calculate_cells();
}

void BackgroundImage::calculate_cells()
{
	cellWidth = sheet_width / ncols;
	cellHeight = sheet_height / nrows;
}

void BackgroundImage::draw()
{
	int currentCol = currentCell % ncols;
	int currentRow = currentCell / ncols;
	int cx = cellWidth * currentCol;
	int cy = cellHeight * currentRow;

	background2->drawAt((x - ref_x) + 1000, y - ref_y, cx, cy, cellWidth, cellHeight);
	background1->drawAt(x - ref_x, y - ref_y, cx, cy, cellWidth, cellHeight);

	if (x < -1000)																			//Sets the moving background
	{
		x = 0;
	}
	
}

BackgroundImage::~BackgroundImage() {
	if (background1)
		delete background1;
	if (background2)
		delete background2;
}
