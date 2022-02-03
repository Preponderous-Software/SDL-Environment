// goal: build a self-contained environment so I don't have to
//		 do all this stuff every time.

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <fstream>

#include "objects/Text.h"
#include "objects/Button.h"

class Environment {
  public:
	// tors
	Environment();
	~Environment();
	
	// primary methods
	void init();
	void loadMedia();
	void cleanUp();
	
	// secondary methods
	bool isRunning();
	bool pollEvent();
	SDL_Event* getEvent();
	
	// setters
	void setRunning(bool b);
	void setScreenWidth(int w);
	void setScreenHeight(int h);
	void setTitle(std::string newTitle);
	void setFontSize(int size);
	
	// getters
	int getW();
	int getH();
	SDL_Renderer* getRenderer();
	TTF_Font* getFont();
	
	// rendering methods
	void setRenderColor(int r, int g, int b, int a);
	void clear();
	void present();
	
	// drawing methods
	void drawRectangle(int x, int y, int w, int h);
	
  private:
	int screenWidth;
	int screenHeight;
  
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	
	TTF_Font* font = NULL;
	int fontSize = 16;
	
	std::string title;
	
	SDL_Event event;
	
	bool running;
	
	std::ofstream log;
};