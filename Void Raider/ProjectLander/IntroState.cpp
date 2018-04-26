#include "introstate.h"
#include "playstate.h"
#include "StartScreen.h"

IntroState IntroState::m_IntroState;
StartScreen *startScreen;


void IntroState::Init()
{
	startScreen = new StartScreen(0, 0, 0, 1, 1, "MainScreen.bmp");

	m_IntroState.mainMenuView = false;
}

void IntroState::Cleanup()
{
	
}

void IntroState::Pause()
{
	printf("CIntroState Pause\n");
}

void IntroState::Resume()
{
	printf("CIntroState Resume\n");
}

void IntroState::updateState(GameEngine* game)
{
	if (m_IntroState.isNextState == true)
	{
		m_IntroState.isNextState == false;
		game->PopState();
		game->PushState(CPlayState::Instance());					//changes state
					
		game->HandleEvents();									
	}
}

 void IntroState::setupState(bool stateChange, bool introView)
{

	m_IntroState.isNextState = stateChange;
	m_IntroState.mainMenuView = introView;
	
}
void IntroState::keyboard(unsigned char key, int x, int y)
{
	
		switch (key)
		{
		case VK_SPACE:												//when enter is pressed start the game
			if (m_IntroState.mainMenuView == false)
			{
				m_IntroState.setupState(true, false);
			}
			break;
						
		case 'i': case 'I':

			if (m_IntroState.mainMenuView == false)
			{
				startScreen = new StartScreen(0, 0, 0, 1, 1, "InstructionScreen.bmp");		
				m_IntroState.setupState(false, true);

			}
			else if (m_IntroState.mainMenuView == true) {
				startScreen = new StartScreen(0, 0, 0, 1, 1, "MainScreen.bmp");
				m_IntroState.setupState(false, false);

			}
			break;

		case VK_ESCAPE: 
			if (m_IntroState.mainMenuView == false)
			{
				exit(0);
			}
			break;
			
		}
}

void IntroState::HandleEvents(GameEngine* game)
{	
		glutKeyboardFunc(keyboard);	
}

void IntroState::Update(GameEngine* game)
{
	m_IntroState.updateState(game);												// Checks if its time to start the game.
}


void IntroState::drawString(void *font, float x, float y, const char *str)		// Draws strings onto the OpenGL screen.
{
	char *ch;
	glRasterPos3f(x, y, 0.0);
	for (ch = (char*)str; *ch; ch++)
	glutBitmapCharacter(font, (int)*ch);
}

void IntroState::Draw(GameEngine* game)
{
	glClear(GL_COLOR_BUFFER_BIT);

	startScreen->draw();
	
	glutSwapBuffers();
}

		
	
		
	
	
	