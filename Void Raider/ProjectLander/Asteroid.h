#pragma once

#include "Bitmap.h"
#include "Projectile.h"

class Asteroid {	

public:
	Asteroid(float ixpos, float iypos, float ixvel, float iyvel, bool iloaded);
	Asteroid(int incols, int inrows, const char *file);
	void Draw();								//Constructs the projectile on screen
	void Move();								//Moves the projectile's X and Y positions by corresponding velocities
	void SetVel(float ixvel, float iyvel);		//Sets a new value for the X and Y velocities
	void SetPos(float ixpos, float iypos);		//Sets a new value for the X and Y positions
	void SetLoaded(bool iloaded);
	void CheckCollision(Projectile projectile);	//Checks for collision with a projectile

	float GetVelx() { return xvel; };			//Returns the value of the projectile's X-velocity
	float GetVely() { return yvel; };			//Returns the value of the projectile's Y-velocity
	float GetPosx() { return xpos; };			//Returns the value of the projectile's X-position
	float GetPosy() { return ypos; };			//Returns the value of the projectile's Y-position

	bool GetLoaded() { return loaded; }			//Returns the reloaded variable

	void setSpriteSheetDimensions(int w, int h);

private:
	float xpos, ypos, xvel, yvel;
	bool loaded;
	Bitmap *asteroid;
	float  width, height;
	int ncols, nrows;
	int currentCell;
	int ref_x, ref_y;
	int cellWidth, cellHeight;

	int sheet_width, sheet_height;
	void calculate_cells();

};
