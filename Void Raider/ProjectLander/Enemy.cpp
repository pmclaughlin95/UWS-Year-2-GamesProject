#include "Enemy.h"
#include "Rnd.h"




Enemy::Enemy(int incols, int inrows, const char *file)
{	
	pic = new Bitmap(file, true);

	xpos = 1000;				
	ypos = rnd(0, 500);
	xvel = -2;
	yvel = rnd(1, 9)/10;
	xStopPos = rnd(600, 900);
	loaded = false;			//Set value to loaded so projectile can be fired
	isAlive = true;
							
	width = pic->getWidth();
	height = pic->getHeight();

	ncols = incols;
	nrows = inrows;

	currentCell = 0;
	setSpriteSheetDimensions(width, height);	

	ref_x = ref_y = 0;	
}

void Enemy::move()
{
	xpos += xvel;
	if (xpos <= xStopPos) {
		ypos += yvel;
		xvel = 0;
	}
}

void Enemy::Draw()
{
	int currentCol = currentCell % ncols;
	int currentRow = currentCell / ncols;
	int cx = cellWidth * currentCol;
	int cy = cellHeight * currentRow;
	
	pic->drawAt(xpos - ref_x, ypos - ref_y, cx, cy, cellWidth, cellHeight);
}

void Enemy::calculate_cells() 
{
	cellWidth = sheet_width / ncols;
	cellHeight = sheet_height / nrows;
}

void Enemy::setSpriteSheetDimensions(int w, int h) {
	sheet_width = w;
	sheet_height = h;
	calculate_cells();
}

void Enemy::CheckCollision(Projectile projectile) {
	if (int((projectile.GetPosx() > GetPosx() - 30) && (projectile.GetPosx() < GetPosx() + 30)))
	{
		if (int((projectile.GetPosy() >GetPosy() - 50) && (projectile.GetPosy() < GetPosy() + 50)))
		{
			SetPos(-100, -100);	
			isAlive = false;
		}
	}
}

void Enemy::CheckScreenEdges(int windowH)
{

	if (GetPosy() > (windowH - 80))		//if enemy offscreen (top)
	{
		SetVelY(-1);					//bounce enemy back down
	}
	if (GetPosy() < 0)					//if enemy offscreen (top)
	{
		SetVelY(1);						//bounce enemy back down
	}

}



void Enemy::SetPos(float ixpos, float iypos)	//Object operation to set projectile position
{
	xpos = ixpos; ypos = iypos;
}