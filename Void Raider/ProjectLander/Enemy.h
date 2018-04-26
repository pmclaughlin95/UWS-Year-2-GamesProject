#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Bitmap.h"
#include "Player.h"

class Enemy
{
public:
	Enemy(int incols, int inrows, const char *file);
	void move();
	void Draw();
	
	void CheckScreenEdges(int windowH);
	void CheckCollision(Projectile projectile);

	void SetVelX(float ixvel) { xvel = ixvel; }	//Sets a new value for the X and Y velocities
	void SetVelY(float iyvel) { yvel = iyvel; }
	void SetPos(float ixpos, float iypos);		//Sets a new value for the X and Y positions
	void SetIsAlive(bool toggleDeath) {isAlive = toggleDeath;}							//Sets the value for the enemy being alive

	float GetVelx() { return xvel; };			//Returns the value of the projectile's X-velocity
	float GetVely() { return yvel; };			//Returns the value of the projectile's Y-velocity
	float GetPosx() { return xpos; };			//Returns the value of the projectile's X-position
	float GetPosy() { return ypos; };			//Returns the value of the projectile's Y-position
	bool GetIsAlive() { return isAlive; };		//Returns the value of the Player's score
	
private:
	void calculate_cells();
	void setSpriteSheetDimensions(int w, int h);
	float xpos, ypos, xvel, yvel;
	bool loaded, isAlive;
	float width, height;
	int xStopPos;

	


	Bitmap* pic;
	int ref_x, ref_y;
	int sheet_width, sheet_height;
	int ncols, nrows;
	int currentCell;	
	int cellWidth, cellHeight;
	
};

#endif

