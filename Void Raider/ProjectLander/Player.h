#pragma once

#include "Bitmap.h"
#include "Projectile.h"
#include "Asteroid.h"

class Player {	

	
public:
	Player(float ixpos, float iypos, float ixvel, float iyvel, int ihealth, int ilives);
	Player(int incols, int inrows, const char *file);
	void Draw();								//Constructs the Player on screen
	void Move();
	
	void CheckCollision(Projectile projectile, Asteroid asteroid);
	void CheckScreenEdges(int windowH);

	float GetVelx() { return xvel; };			//Returns the value of the Player's X-velocity
	float GetVely() { return yvel; };			//Returns the value of the Player's Y-velocity
	float GetPosx() { return xpos; };			//Returns the value of the Player's X-position
	float GetPosy() { return ypos; };			//Returns the value of the Player's Y-position

	void SetVel(float ixvel, float iyvel);			//Moves the Player's X and Y positions by corresponding velocities
	void SetVelX(float ixvel) { xvel = ixvel; }		//Sets a new value for the X and Y velocities
	void SetVelY(float iyvel) { yvel = iyvel; }
	void SetPos(float ixpos, float iypos);			//Sets a new value for the X and Y positions

	int GetHealth() { return health; }				//Returns the value of the Player's health	
	//int GetScore() { return totalScore; };			//Returns the value of the Player's score

	void addPoints(int newPoints);
	
	void setSpriteSheetDimensions(int w, int h);

	float health;
	int score;
	int totalScore;

private:
	float xpos, ypos, xvel, yvel;
		
	Bitmap *bullet;
	
	float  width, height;
	int ncols, nrows;
	int currentCell;
	int ref_x, ref_y;
	int cellWidth, cellHeight;

	int sheet_width, sheet_height;
	void calculate_cells();
};
