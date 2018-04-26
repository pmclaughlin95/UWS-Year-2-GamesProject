

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
using namespace std;
#include <vector>
class GameState;

class GameEngine
{
public:
	GameEngine();
	void Init();
	void Cleanup();
	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return running; }
	void Quit() { running = false; }

private:
	
	vector<GameState*> states;
	int wHeight;
	int wWidth;
	bool running;
	bool m_fullscreen;
	float windowW = 1000;
	float windowH = 500;	
};

#endif
