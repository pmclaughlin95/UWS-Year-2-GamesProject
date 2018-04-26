#include "playstate.h"
#include "GameOverState.h"

#include "Rnd.h"
#include <string>
#include<sstream>	

#include "Player.h"
#include "Enemy.h"
#include "BackgroundImage.h"
#include "Projectile.h"
#include "Asteroid.h"

CPlayState CPlayState::m_PlayState;

Player *Ship;
BackgroundImage *background;

Projectile *P1;
Projectile *EnemyBullet1;
Projectile *EnemyBullet2;
Projectile *EnemyBullet3;
Projectile *EnemyBullet4;

Asteroid *A1;
Asteroid *A2;
Asteroid *A3;

Enemy *E1;
Enemy *E2;
Enemy *E3;
Enemy *E4;

int score = 0;

void CPlayState::Init()
{
	background = new BackgroundImage(0, 0, 0, 1, 1, "RollingBackground1.bmp");									 
	Ship = new Player(1, 1, "PlayerShip.bmp"); 

	P1 = new Projectile(1, 1, "PlayerProjectile2.bmp");

	EnemyBullet1 = new Projectile(1, 1, "EnemyProjectile2.bmp");
	EnemyBullet2 = new Projectile(1, 1, "EnemyProjectile2.bmp");
	EnemyBullet3 = new Projectile(1, 1, "EnemyProjectile2.bmp");
	EnemyBullet4 = new Projectile(1, 1, "EnemyProjectile2.bmp");
	
	A1 = new Asteroid(1, 1, "Asteroid.bmp");
	A2 = new  Asteroid(1, 1, "Asteroid.bmp");
	A3 = new Asteroid(1, 1, "Asteroid.bmp");

	E1 = new Enemy(1, 1, "EnemyShip.bmp");
	E2 = new  Enemy(1, 1, "EnemyShip.bmp");
	E3 = new Enemy(1, 1, "EnemyShip.bmp");
	E4 = new Enemy(1, 1, "EnemyShip.bmp");
}

void CPlayState::EnemySpawner() {
	if ((E1->GetIsAlive() == false) && (E2->GetIsAlive() == false) && (E3->GetIsAlive() == false) && (E4->GetIsAlive() == false))
	{
		if (score > 500)
		{
			E1->SetIsAlive(true);
			
			E1 = new Enemy(1, 1, "EnemyShip.bmp");
			
		}
		if (score > 5000)
		{
			E2->SetIsAlive(true);
			E2 = new  Enemy(1, 1, "EnemyShip.bmp");
		
		}
		if (score > 10000)
		{
			E3->SetIsAlive(true); E3 = new Enemy(1, 1, "EnemyShip.bmp"); E3->SetPos(800, rnd(0, 500));
		}
		if (score > 20000)
		{
			E4->SetIsAlive(true);
			E4 = new Enemy(1, 1, "EnemyShip.bmp");
		}
	}
}

void CPlayState::Cleanup()
{
	printf("CPlayState Cleanup\n");	
}

void CPlayState::Pause()
{
	printf("CPlayState Pause\n");
}

void CPlayState::Resume()
{
	printf("CPlayState Resume\n");
}


void CPlayState::keyboard(unsigned char key, int x, int y)
{
	switch (key)															
	{
	case 'w':
		
		Ship->SetVel(0, (Ship->GetVely() + 0.6));						
								
		break;
	case 's':
		Ship->SetVel(0, (Ship->GetVely() - 0.6));					
																
		break;
	case 'f': 																		// Fires player weapon.								
		if ((P1->GetLoaded()) == true) {
			P1->SetLoaded(false);
			P1->SetVel(15, 0);										
			P1->SetPos(Ship->GetPosx() + 100, Ship->GetPosy() + 35);	

		}
		break;
	}
}


void CPlayState::HandleEvents(GameEngine* game)
{	
	glutKeyboardFunc(m_PlayState.keyboard);	
}

void CPlayState::Update(GameEngine* game)
{
	if (Ship->GetHealth() <= 0)
	{
		game->PopState();
		game->PushState(GameOverState::Instance());		//Changes game state.
		game->HandleEvents();
	}

	
	A1->CheckCollision(*P1);							//check collison of player bullet and asteroids.
	A2->CheckCollision(*P1);
	A3->CheckCollision(*P1);

	E1->CheckCollision(*P1);
	E2->CheckCollision(*P1);
	E3->CheckCollision(*P1);
	E4->CheckCollision(*P1);

	score++;

	Ship->CheckCollision(*EnemyBullet1, *A1);	
	Ship->CheckCollision(*EnemyBullet2, *A2);
	Ship->CheckCollision(*EnemyBullet3, *A3);
	Ship->CheckCollision(*EnemyBullet4, *A3);
	
	E1->CheckScreenEdges(windowH);						// bounce enemy away from screen edges
	E2->CheckScreenEdges(windowH);						// bounce enemy away from screen edges
	E3->CheckScreenEdges(windowH);						// bounce enemy away from screen edges
	E4->CheckScreenEdges(windowH);						// bounce enemy away from screen edges

	Ship->CheckScreenEdges(windowH);					// bounce player away from screen edges
}


void CPlayState::setUpObjects()			
{
	if (A1->GetLoaded() == true) {
		A1->SetPos(1000, rnd(0, 300));
		A1->SetLoaded(false);
	}

	if (A2->GetLoaded() == true) {
		A2->SetPos(1000, rnd(300, 600));
		A2->SetLoaded(false);
	}

	if (A3->GetLoaded() == true) {
		A3->SetPos(1000, rnd(600, 1000));
		A3->SetLoaded(false);
	}
	//tests for bullet firing
	if ((EnemyBullet1->GetLoaded()) == true) {							//Check if the enemy ship can fire
		EnemyBullet1->SetLoaded(false);
		EnemyBullet1->SetVel(-5, 0);
		EnemyBullet1->SetPos(E1->GetPosx() , E1->GetPosy());
	}
	if ((EnemyBullet2->GetLoaded()) == true) {							//Check if the enemy ship can fire
		EnemyBullet2->SetLoaded(false);
		EnemyBullet2->SetVel(-5, 0);
		EnemyBullet2->SetPos(E2->GetPosx(), E2->GetPosy());
	}
	if ((EnemyBullet3->GetLoaded()) == true) {							//Check if the enemy ship can fire
		EnemyBullet3->SetLoaded(false);
		EnemyBullet3->SetVel(-5, 0);
		EnemyBullet3->SetPos(E3->GetPosx() , E3->GetPosy());
	}
	if ((EnemyBullet4->GetLoaded()) == true) {							//Check if the enemy ship can fire
		EnemyBullet4->SetLoaded(false);
		EnemyBullet4->SetVel(-5, 0);
		EnemyBullet4->SetPos(E4->GetPosx(), E4->GetPosy());
	}

	background->move();
	Ship->Move();
	P1->Move();
	A1->Move();
	A2->Move();
	A3->Move();

	if (E1->GetIsAlive() == true)
	{
		E1->move();
	}
	if (E2->GetIsAlive() == true)
	{
		E2->move();
	}
	if (E3->GetIsAlive() == true)
	{
		E3->move();
	}
	if (E4->GetIsAlive() == true)
	{
		E4->move();
	}

	EnemyBullet1->Move();
	EnemyBullet2->Move();
	EnemyBullet3->Move();
	EnemyBullet4->Move();
	

}

void drawString(void *font, float x, float y, const char *str)		// Draws strings onto the OpenGL screen
{
	char *ch;
	glRasterPos3f(x, y, 0.0);
	for (ch = (char*)str; *ch; ch++)
		glutBitmapCharacter(font, (int)*ch);
}

std::string IntToStr(int n)				//Converts integers to strings
{
	std::ostringstream result;
	result << n;
	return result.str();
}

void CPlayState::Draw(GameEngine* game)
{
	setUpObjects();// Updates our objects positions before drawn

	EnemySpawner();

	glClear(GL_COLOR_BUFFER_BIT);

	background->draw();

	Ship->Draw();

	P1->Draw();

	A1->Draw();
	A2->Draw();
	A3->Draw();

	E1->Draw();								
	E2->Draw();
	E3->Draw();
	E4->Draw();

	EnemyBullet1->Draw(); 
	EnemyBullet2->Draw();
	EnemyBullet3->Draw();
	EnemyBullet4->Draw();

	glColor3f(1, 1, 0);

	string health = IntToStr(Ship->GetHealth());						//convert our int health value into a printable string valuable 
	drawString(GLUT_BITMAP_8_BY_13, 20, 470, "Health: ");
	drawString(GLUT_BITMAP_8_BY_13, 75, 470, health.c_str());		

	string score = IntToStr(m_PlayState.score);						//convert out int score value into a printable string valuable 
	drawString(GLUT_BITMAP_8_BY_13, 120, 470, "score: ");
	drawString(GLUT_BITMAP_8_BY_13, 180, 470, score.c_str());		

	glutSwapBuffers();
}

