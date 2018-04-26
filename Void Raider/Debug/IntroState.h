

#ifndef INTROSTATE_H
#define INTROSTATE_H
#include "gamestate.h"

class IntroState : public GameState
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
	static void IntroState::keyboard(unsigned char key, int x, int y);
	void setupState(bool stateChange, bool instruct);

	static IntroState* Instance() {
		
		return &m_IntroState;
	}

	
protected:
	IntroState() { }
	

private:
	static IntroState m_IntroState;
	bool isNextState;
	bool mainMenuView;


};

#endif
