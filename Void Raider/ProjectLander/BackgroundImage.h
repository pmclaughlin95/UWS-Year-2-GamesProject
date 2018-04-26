#pragma once

#ifndef BACKGROUNDIMAGE_H
#define BACKGROUNDIMAGE_H

class BackgroundImage
{
public:
	BackgroundImage(int ix, int iy, int idx, int icols, int irows,  const char *file);
	void draw();
	void init(int ix, int iy, int idx, int icols, int irows);

	void setSpriteSheetDimensions(int w, int h);
	void move() { x += -1; }

	~BackgroundImage();
	
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