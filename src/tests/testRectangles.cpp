#include "../header/GraphicsEnv.h"
#include <cstdlib>

// create environment
GraphicsEnv environment;

int xpos = environment.getW()/2 - 50;
int ypos = environment.getH()/2 - 50;

int xvel = 0;
int yvel = 0;

int xtarget = 0;
int ytarget = 0;

void drawRects() {
	// render black square
	environment.setRenderColor(0x00, 0x00, 0x00, 0xFF);
	environment.drawRectangle(xpos, ypos, 100, 100);
	
	// render green square
	environment.setRenderColor(0x00, 200, 0x00, 0xFF);
	environment.drawRectangle(xtarget - 5, ytarget - 5, 10, 10);
}

int chooseRandomX() {
	return rand() % environment.getW();
}

int chooseRandomY() {
	return rand() % environment.getH();
}

void changeRectVel() {
	// if left, go right
	if (xpos < xtarget) {
		xvel = 1;
	}
	
	// if right, go left
	if (xpos > xtarget) {
		xvel = -1;
	}
	
	// if up, go down
	if (ypos < ytarget) {
		yvel = 1;
	}
	
	// if down, go up
	if (ypos > ytarget) {
		yvel = -1;
	}
	
	// if reached, stop
	if (xpos == xtarget) {
		xvel = 0;
		
	}
	
	if (ypos == ytarget) {
		yvel = 0;
	}
	
	if (xpos == xtarget && ypos == ytarget) {
		xtarget = chooseRandomX();
		ytarget = chooseRandomY();
	}
}

void changeRectPos() {
	xpos += xvel;
	ypos += yvel;
}

int main(int argc, char* args[]) {	
	// set title
	environment.setTitle("GraphicsEnv Test 5");
	
	// set width and height of the screen
	environment.setScreenWidth(700);
	environment.setScreenHeight(700);
	
	// initialize
	environment.init();
	
	// load media
	environment.loadMedia();
	
	// main loop
	while (environment.isRunning()) {
		while (environment.pollEvent() != 0) {
			if (environment.getEvent()->type == SDL_QUIT) {
				environment.setRunning(false);
			}
		}
		// clear environment
		environment.setRenderColor(0xFF, 0xFF, 0xFF, 0XFF);
		environment.clear();
		
		// draw rectangle
		drawRects();
		
		// change velocity
		changeRectVel();
		
		// change x and y
		changeRectPos();
		
		// present environment
		environment.present();
	}
	
	// clean up environment
	environment.cleanUp();
}