#include "GameOverState.h"
#include "StartScreen.h"

GameOverState GameOverState::m_GameOverState;

StartScreen *GameOverScreen;

void GameOverState::Init()
{
	GameOverScreen = new StartScreen(0, 0, 0, 1, 1, "GaymOver.bmp");
}

void GameOverState::Cleanup()
{

}

void GameOverState::Pause()
{
	printf("CIntroState Pause\n");
}

void GameOverState::Resume()
{
	printf("CIntroState Resume\n");
}

void GameOverState::updateState(GameEngine* game)
{
	if (m_GameOverState.GameOverView == true)
	{
		exit(0);
	}
}

void GameOverState::setupState(bool stateChange, bool exit)
{
	m_GameOverState.isNextState = stateChange;
	m_GameOverState.GameOverView = exit;
}	


void GameOverState::keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'M': case 'm':												//Supposed to reset the game but it causes problems
		
		m_GameOverState.setupState(true, false);
		break;


	case 'e': case 'E':
		m_GameOverState.setupState(false, true);
		break;
	}
}

void GameOverState::HandleEvents(GameEngine* game)
{
	glutKeyboardFunc(keyboard);
}

void GameOverState::Update(GameEngine* game)
{
	m_GameOverState.updateState(game);
}


void GameOverState::drawString(void *font, float x, float y, const char *str)		// Draws strings onto the OpenGL screen
{
	char *ch;
	glRasterPos3f(x, y, 0.0);
	for (ch = (char*)str; *ch; ch++)
	glutBitmapCharacter(font, (int)*ch);
}

void GameOverState::Draw(GameEngine* game)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);

	GameOverScreen->draw();

	glutSwapBuffers();
}






