#include <gl/glut.h>
#include <iostream>

#include "gameengine.h"
#include "gamestate.h"


GameEngine::GameEngine()
{
	running = true;
	Init();
	
}

void GameEngine::Init()
{
	std::cout << "Game Engine init" << std::endl;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(windowW, windowH);
	glutCreateWindow("Lunar Lander");
	gluOrtho2D(0, windowW, 0, windowH);
	
}


void GameEngine::Cleanup()
{
	
	while (!states.empty()) {					// cleanup the all states
		states.back()->Cleanup();
		states.pop_back();
	}
}

void GameEngine::ChangeState(GameState* state)
{
	std::cout << "state changed" << std::endl;

	
	if (!states.empty()) {						// cleanup the current state
		states.back()->Cleanup();
		states.pop_back();
	}

	
	states.push_back(state);					// store and init the new state
	states.back()->Init();
}

void GameEngine::PushState(GameState* state)
{
	
	if (!states.empty()) {						// pause current state
		states.back()->Pause();
	}

	
	states.push_back(state);					//store and init the new state
	states.back()->Init();
}

void GameEngine::PopState()
{
	
	if (!states.empty()) {						// cleanup the current state
		states.back()->Cleanup();
		states.pop_back();
	}

	 
	if (!states.empty()) {						//resume previous state
		states.back()->Resume();
	}
}


void GameEngine::HandleEvents()
{
	states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	
	states.back()->Update(this);				// let the state update the game

}

void GameEngine::Draw()
{
	
	states.back()->Draw(this);					// let the state draw the screen

}



