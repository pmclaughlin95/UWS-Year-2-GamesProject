#pragma once
//#include<gl/glut.h>
//#include<cmath>
#include "Bitmap.h"

#ifndef StartScreen_H
#define StartScreen_H

class StartScreen
{
public:
	StartScreen(int ix, int iy, int idx, int icols, int irows, const char *file);
	void draw();
	void init(int ix, int iy, int idx, int icols, int irows);

	void setSpriteSheetDimensions(int w, int h);
	void move() { x += -1; }

	~StartScreen();

private:
	int x, y;
	float dx;

	float  width, height;
	int ncols, nrows;
	int currentCell;
	int ref_x, ref_y;
	int cellWidth, cellHeight;

	int sheet_width, sheet_height;
	void calculate_cells();
};
#endif