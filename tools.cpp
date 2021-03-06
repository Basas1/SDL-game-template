#pragma once
#include "tools.h"
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


//Load Texture
SDL_Texture* load_texture(std::string path) {
	//The final texture
	SDL_Texture* new_texture = NULL;
	//Load image at specified path
	SDL_Surface* loaded_surface = IMG_Load(path.c_str());
	if (loaded_surface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
		//Create texture from surface pixels
		new_texture = SDL_CreateTextureFromSurface(main_renderer, loaded_surface);
		if (new_texture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loaded_surface);
	}

	return new_texture;
}

//Render text to screen
void render_text(int x, int y, std::string text, TTF_Font* font) {
	//Text texture
	//SDL_Texture* text_texture = NULL;
	SDL_Texture* text_texture = SDL_CreateTexture(main_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 500, 500);
	SDL_Color text_color = { 255, 255, 255 };
	//Render text surface
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	//Create texture from surface pixels
	text_texture = SDL_CreateTextureFromSurface(main_renderer, text_surface);
	SDL_Rect render_quad = { x, y, text_surface->w, text_surface->h };
	//SDL_RenderFillRect(main_renderer, &renderQuad);
	SDL_RenderCopyEx(main_renderer, text_texture, NULL, &render_quad, 0.0, NULL, SDL_FLIP_NONE);
	SDL_FreeSurface(text_surface);
	SDL_DestroyTexture(text_texture);
}

//Copy-pasted from "http://sdl.beuc.net/sdl.wiki/Pixel_Access"
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp) {
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16 *)p;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32 *)p;
		break;

	default:
		return 0;       /* shouldn't happen, but avoids warnings */
	}
}


