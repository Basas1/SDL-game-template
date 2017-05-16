#pragma once
#include "Movable_object.h"
class Fireball : public Movable_object {
public:
	Fireball(int x, int y, bool left);
	~Fireball();

	//Move method
	void move();

	void logic();

	//Render object
	void render();

};

