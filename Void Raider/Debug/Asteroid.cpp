#include "Asteroid.h"
#include "gl/glut.h"
#include "Rnd.h"

Asteroid::Asteroid(float ixpos, float iypos, float ixvel, float iyvel, bool iloaded) //Constructor 
{
	xpos = ixpos;
	ypos = iypos;
	xvel = ixvel;
	yvel = iyvel;
	loaded = iloaded;
}

Asteroid::Asteroid(int incols, int inrows, const char *file)//Constructor
{
	asteroid = new Bitmap(file, true);					//Assigns bitmap to the projectile

	xpos = 1200;										//Spawns projectile offscreen until fired
	ypos = 0;
	xvel = -1;
	yvel = 0;
	loaded = false;										//Set value to loaded so projectile can be fired

	width = asteroid->getWidth();
	height = asteroid->getHeight();

	ncols = incols;
	nrows = inrows;

	currentCell = 0;
	setSpriteSheetDimensions(width, height);

	ref_x = ref_y = 0;

}

void Asteroid::SetVel(float ixvel, float iyvel)			//Object operation to set projectile velocity
{
	xvel = ixvel; yvel = iyvel;
}

void Asteroid::SetPos(float ixpos, float iypos)	//Object operation to set projectile position
{
	xpos = ixpos; ypos = iypos;
}

void Asteroid::SetLoaded(bool iloaded)			//Object operation to confirm the projectile can be fired
{
	loaded = iloaded;
}

void Asteroid::Draw()								//Draws the projectile onscreen
{
	int currentCol = currentCell % ncols;
	int currentRow = currentCell / ncols;
	int cx = cellWidth * currentCol;
	int cy = cellHeight * currentRow;

	asteroid->drawAt(xpos - ref_x, ypos - ref_y, cx, cy, cellWidth, cellHeight);
}

void Asteroid::Move()				//Moves the projectile by the assigned velocity values
{
	xpos += xvel;					//moves the x-position of the projectile by the current x-velocity
				
	if ((xpos < 0))				//Detects lander moving offscreen
	{
		loaded = true;				//Allows projectile to fire again
	}
}

void Asteroid::setSpriteSheetDimensions(int w, int h) {//Bitmap utility
	sheet_width = w;
	sheet_height = h;
	calculate_cells();
}

void Asteroid::calculate_cells() {//Bitmap utility
									
	cellWidth = sheet_width / ncols;
	cellHeight = sheet_height / nrows;
}

void Asteroid::CheckCollision(Projectile projectile) {
	if (int((projectile.GetPosx() > GetPosx() - 30) && (projectile.GetPosx() < GetPosx() + 30)))
	{
		if (int((projectile.GetPosy() >GetPosy() - 30) && (projectile.GetPosy() < GetPosy() + 30)))
		{
			SetPos(-100, -100);			
		}
	}
}