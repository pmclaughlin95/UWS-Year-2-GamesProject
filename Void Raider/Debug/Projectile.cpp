#include "Projectile.h"

Bitmap* bullet;
Projectile::Projectile(float ixpos, float iypos, float ixvel, float iyvel, bool iloaded) //Constructor 
{
	xpos = ixpos;
	ypos = iypos;
	xvel = ixvel;
	yvel = iyvel;
	loaded = iloaded;
}

Projectile::Projectile(int incols, int inrows, const char *file)//Constructor
{
	bullet = new Bitmap(file, true); //Assigns bitmap to the projectile
	

	xpos = 250;				//Spawns projectile offscreen until fired
	ypos = 600;
	xvel = 0;
	yvel = 0;
	loaded = true;			//Set value to loaded so projectile can be fired

	//Bitmap Essentials

	width = bullet->getWidth();
	height = bullet->getHeight();

	ncols = incols;
	nrows = inrows;

	currentCell = 0;
	setSpriteSheetDimensions(width, height);

	ref_x = ref_y = 0;

}

void Projectile::SetVel(float ixvel, float iyvel)	//Object operation to set projectile velocity
{
	xvel = ixvel; yvel = iyvel;
}

void Projectile::SetPos(float ixpos, float iypos)	//Object operation to set projectile position
{
	xpos = ixpos; ypos = iypos;
}

void Projectile::SetLoaded(bool iloaded)			//Object operation to confirm the projectile can be fired
{			
	loaded = iloaded;
}

void Projectile::Draw()								//Draws the projectile onscreen
{							
	int currentCol = currentCell % ncols;
	int currentRow = currentCell / ncols;
	int cx = cellWidth * currentCol;
	int cy = cellHeight * currentRow;

	bullet->drawAt(xpos - ref_x, ypos - ref_y, cx, cy, cellWidth, cellHeight);

	
}

void Projectile::Move()				//Moves the projectile by the assigned velocity values
{							
	xpos += xvel;					//moves the x-position of the projectile by the current x-velocity
	ypos += yvel;					//moves the y-position of the projectile by the current y-velocity
	
	if (xpos > 1000)				//Detects lander moving offscreen
	{										
		loaded = true;				//Allows projectile to fire again
	}

	if (xpos < 0)				//Detects lander moving offscreen
	{
		loaded = true;				//Allows projectile to fire again
	}
}

void Projectile::setSpriteSheetDimensions(int w, int h) {//Bitmap utility
	sheet_width = w;
	sheet_height = h;
	calculate_cells();
}

void Projectile::calculate_cells() {
	
	cellWidth = sheet_width / ncols;
	cellHeight = sheet_height / nrows;
}

void Projectile::CheckCollision(Projectile projectile) {
	if (int((projectile.GetPosx() > GetPosx() - 30) && (projectile.GetPosx() < GetPosx() + 30)))
	{
		if (int((projectile.GetPosy() >GetPosy() - 30) && (projectile.GetPosy() < GetPosy() + 30)))
		{
			SetPos(-100, -100);			
		}
	}
}