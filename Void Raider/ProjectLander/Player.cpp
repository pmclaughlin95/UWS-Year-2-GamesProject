#include "Player.h"
#include "gl/glut.h"
#include <ctime>
#include <string>
#include <sstream>	
#include <stdexcept>
#include "Asteroid.h"

Bitmap *player;



Player::Player(float ixpos, float iypos, float ixvel, float iyvel, int ihealth, int ilives) //Constructor 
{
	xpos = ixpos;
	ypos = iypos;
	xvel = ixvel;
	yvel = iyvel;
	score = 0;
	health = ihealth;
	
}
Player::Player(int incols, int inrows, const char *file)
{
	player = new Bitmap(file, true);									

	xpos = 100;																
	ypos = 250;
	xvel = 0;
	yvel = 0;
	health = 500;
	score = 0;

	
	//Bitmap Essentials
	width = player->getWidth();
	height = player->getHeight();
	ncols = incols;
	nrows = inrows;
	currentCell = 0;
	setSpriteSheetDimensions(width, height);
	ref_x = ref_y = 0;
	
}
void Player::SetVel(float ixvel, float iyvel)								//Object operation to set projectile velocity
{
	xvel = ixvel; yvel = iyvel;
}

void Player::SetPos(float ixpos, float iypos)								//Object operation to set projectile position
{
	xpos = ixpos; ypos = iypos;
}

void Player::Draw()															
{
	int currentCol = currentCell % ncols;
	int currentRow = currentCell / ncols;
	int cx = cellWidth * currentCol;
	int cy = cellHeight * currentRow;

	player->drawAt(xpos - ref_x, ypos - ref_y, cx, cy, cellWidth, cellHeight);
}


void Player::CheckScreenEdges(int windowH)
{
	if (GetPosy() > (windowH - 80))							//if player offscreen (top)
	{
		SetVel(0, -0.6);									//bounce player back down
	}
	if (GetPosy() < 0)										//if player offscreen (bottom)
	{
		SetVel(0, 0.6);										//bounce player back up
	}
	totalScore += score;
}


void Player::addPoints(int newPoints)
{
	score += newPoints;
	score = score;
	totalScore += score;
}


void Player::Move()						//Moves the projectile by the assigned velocity values
{										//moves the x-position of the projectile by the current x-velocity
	ypos += yvel;						//moves the y-position of the projectile by the current y-velocity
}

void Player::setSpriteSheetDimensions(int w, int h)					//Bitmap utility
{
	sheet_width = w;
	sheet_height = h;
	calculate_cells();
}

void Player::calculate_cells() {									//Bitmap utility
									
	cellWidth = sheet_width / ncols;
	cellHeight = sheet_height / nrows;
}

void Player::CheckCollision(Projectile projectile, Asteroid asteroid) {
	if (int((projectile.GetPosx() > GetPosx() - 30) && (projectile.GetPosx() < GetPosx() + 30)))
	{
		if (int((projectile.GetPosy() >GetPosy() - 30) && (projectile.GetPosy() < GetPosy() + 30)))
		{
			health -= 1;			
		}
	}

	if (int((asteroid.GetPosx() > GetPosx() - 30) && (asteroid.GetPosx() < GetPosx() + 30)))
	{
		if (int((asteroid.GetPosy() >GetPosy() - 30) && (asteroid.GetPosy() < GetPosy() + 30)))
		{
			health -= 0.5;
		}
	}
}


