/*	B00286864 Lunar Lander
-DrawString() function taken for moducle notes chapter 9
written by Allistair Mcmonnies
-std::string IntToStr(int n) taken from previous Lunar Lander project by B00221736
- all rnd.cpp and rnd.h taken from course material.

*/
#include <gl/glut.h>
#include "GameEngine.h"
#include "IntroState.h"

GameEngine *game;

void keyboard(unsigned char key, int x, int y)
{
	game->HandleEvents();
}	

void timer(int value)
{
	game->Draw();
	game->Update();
	
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{	
	glutInit(&argc, argv);
	game = new GameEngine();
	game->ChangeState(IntroState::Instance());
	
	while (game->Running())
	{			
		glutTimerFunc(10, timer, 0);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
	}	
}
	
	
	
	
		
	

		
	


	
	

