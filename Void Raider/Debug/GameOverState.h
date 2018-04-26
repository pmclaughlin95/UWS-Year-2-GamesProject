
#include "gamestate.h"

#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H


class GameOverState : public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
	void updateState(GameEngine* game);
	void drawString(void *font, float x, float y, const char *str);
	static void GameOverState::keyboard(unsigned char key, int x, int y);

	void setupState(bool stateChange, bool exit);
	static GameOverState* Instance() 
	{
		return &m_GameOverState;
	}
	
protected:
	GameOverState() { }

private:
	static GameOverState m_GameOverState;
	bool isNextState;
	bool GameOverView;
};

#endif
