#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Button {
  public:
	int xpos;
	int ypos;
	int width;
	int height;
	
	SDL_Renderer* renderer;
	
	Button();
	
	void (*hoverFunc)() = NULL;
	void (*mouseDownFunc)() = NULL;
	void (*mouseUpFunc)() = NULL;
	
	void init(int x, int y, int w, int h, SDL_Renderer* r, void (*funcMouseDown)());
	
	void setRenderer(SDL_Renderer* r);
	
	void render();
	
	void handleEvent(SDL_Event* e);
	
	void setHoverFunction(void (*passedFunc)());
	
	void setMouseDownFunction(void (*passedFunc)());
	
	void setMouseUpFunction(void (*passedFunc)());
};
#endif