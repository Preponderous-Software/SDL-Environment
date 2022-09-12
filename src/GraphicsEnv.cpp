#include "header/GraphicsEnv.h"

// tors
GraphicsEnv::GraphicsEnv() {
	title = "GraphicsEnv Default Title";   
	screenWidth = 640;
	screenHeight = 480;
}

GraphicsEnv::~GraphicsEnv() { // dtor
	cleanUp();
}

// primary methods
void GraphicsEnv::init() {          
	log.open("log.txt");
	log << "Initializing!" << std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	running = true;
}
	
void GraphicsEnv::loadMedia() {
	font = TTF_OpenFont("objects/bboron.ttf", fontSize); // credit: https://www.1001fonts.com/arial-fonts.html
	if (font == NULL) {
		log << "Font is NULL!" << std::endl;
		cleanUp();
	}
}

void GraphicsEnv::cleanUp() {
	log << "Cleaning up!" << std::endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	
	log.close();
}

// secondary methods
bool GraphicsEnv::isRunning() {
	return running;
}

bool GraphicsEnv::pollEvent() {
	return SDL_PollEvent(&event);
}

SDL_Event* GraphicsEnv::getEvent() {
	return &event;
}

// setters 
void GraphicsEnv::setRunning(bool b) {
	running = b;
}

void GraphicsEnv::setScreenWidth(int w) {
	screenWidth = w;
}

void GraphicsEnv::setScreenHeight(int h) {
	screenHeight = h;
}

void GraphicsEnv::setTitle(std::string newTitle) {
	title = newTitle;
}

void GraphicsEnv::setFontSize(int size) {
	fontSize = size;
}

// getters
int GraphicsEnv::getW() {
	return screenWidth;
}

int GraphicsEnv::getH() {
	return screenHeight;
}

SDL_Renderer* GraphicsEnv::getRenderer() {
	return renderer;
}

TTF_Font* GraphicsEnv::getFont() {
	return font;
}

// rendering methods
void GraphicsEnv::setRenderColor(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void GraphicsEnv::clear() {
	SDL_RenderClear(renderer);
}

void GraphicsEnv::present() {
	SDL_RenderPresent(renderer);
}

// drawing methods
void GraphicsEnv::drawRectangle(int x, int y, int w, int h) {
	SDL_Rect fillRect = {x, y, w, h};		
	SDL_RenderFillRect(renderer, &fillRect); // draw color using rect
}