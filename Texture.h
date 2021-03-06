#pragma once
#include <SDL.h>
#include <string>

class Texture {
public:
	//Initializes variables
	Texture(SDL_Texture* original_texture);

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool load_from_file(std::string path);

	//Change texture
	void change_texture(SDL_Texture* change_to);

	//Set color modulation
	void set_�olor(Uint8 red, Uint8 green, Uint8 blue);

	//Change texture width
	void set_width(int w);

	//Change texture height
	void set_height(int h);

	//Set texture flip
	void set_flip(SDL_RendererFlip change);

	//Deallocates texture
	void free();

	//Render texture at given point
	void render(int x, int y, bool flip_right = true, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL);

	//Gets image dimensions
	int get_width();
	int get_height();

protected:
	//Actual SDL texture
	SDL_Texture* original_texture;

	//Flip flag
	SDL_RendererFlip flip;

	//Image dimensions
	int width, height;


};

	