#include "Programm_state.h"
#include <SDL.h>
#include "Player.h"
#pragma once
class Game : public Programm_state {
public:
	Game();
	~Game();
	void handle_events();
	void logic();
	void render();

private:
	SDL_Texture* background;
	Player* player_1;
};

