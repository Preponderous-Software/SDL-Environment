#include "Environment.h"

// tors
Environment::Environment() {
	title = "Environment Default Title";   
	screenWidth = 640;
	screenHeight = 480;
}

Environment::~Environment() { // dtor
	cleanUp();
}

// primary methods
void Environment::init() {          
	log.open("log.txt");
	log << "Initializing!" << std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	running = true;
}
	
void Environment::loadMedia() {
	font = TTF_OpenFont("objects/bboron.ttf", fontSize); // credit: https://www.1001fonts.com/arial-fonts.html
	if (font == NULL) {
		log << "Font is NULL!" << std::endl;
		cleanUp();
	}
}

void Environment::cleanUp() {
	log << "Cleaning up!" << std::endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	
	log.close();
}

// secondary methods
bool Environment::isRunning() {
	return running;
}

bool Environment::pollEvent() {
	return SDL_PollEvent(&event);
}

SDL_Event* Environment::getEvent() {
	return &event;
}

// setters 
void Environment::setRunning(bool b) {
	running = b;
}

void Environment::setScreenWidth(int w) {
	screenWidth = w;
}

void Environment::setScreenHeight(int h) {
	screenHeight = h;
}

void Environment::setTitle(std::string newTitle) {
	title = newTitle;
}

void Environment::setFontSize(int size) {
	fontSize = size;
}

// getters
int Environment::getW() {
	return screenWidth;
}

int Environment::getH() {
	return screenHeight;
}

SDL_Renderer* Environment::getRenderer() {
	return renderer;
}

TTF_Font* Environment::getFont() {
	return font;
}

// rendering methods
void Environment::setRenderColor(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Environment::clear() {
	SDL_RenderClear(renderer);
}

void Environment::present() {
	SDL_RenderPresent(renderer);
}

// drawing methods
void Environment::drawRectangle(int x, int y, int w, int h) {
	SDL_Rect fillRect = {x, y, w, h};		
	SDL_RenderFillRect(renderer, &fillRect); // draw color using rect
}