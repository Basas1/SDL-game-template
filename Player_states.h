#pragma once
#include <SDL.h>
#include "Player.h"

class Player_states {
public:

	enum states {
		STAND_STATE,
		RUN_STATE,
		FIRE_STATE,
		JUMP_STATE,
	};
	void change_state(Player& p, int state);
	virtual ~Player_states() {};
	void handle_events(Player& p, SDL_Event& event);
	virtual void logic(Player& p) {};
	virtual void render(Player& p) {};
};

class On_ground : public Player_states {
public:
	On_ground() {};
	void handle_events(Player& p, SDL_Event& event);
	void logic(Player& p);
};

class Stand : public On_ground {
public:
	void logic(Player& p);
	void render(Player& p);

};

class Run : public On_ground {
public:
	void logic(Player& p);
	void render(Player& p);
};

class Jump : public Player_states {
public:
	void logic(Player& p);
	void render(Player& p);
};