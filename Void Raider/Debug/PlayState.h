#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "gamestate.h"

class CPlayState : public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);
	void EnemySpawner();
	static void CPlayState::keyboard(unsigned char key, int x, int y);
	void setUpObjects();

	static CPlayState* Instance() {
		return &m_PlayState;
	}

protected:
	CPlayState() { }

private:
	static CPlayState m_PlayState;
	float windowW = 1000;
	float windowH = 500;
	int score;
	
};

#endif

