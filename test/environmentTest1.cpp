#include "Environment.h"

int main(int argc, char* args[]) {
	// create environment
	Environment environment;
	
	// set title
	environment.setTitle("Environment Test 1");
	
	// set width and height of the screen
	environment.setScreenWidth(400);
	environment.setScreenHeight(400);
	
	// initialize
	environment.init();
	
	// load media
	environment.loadMedia();
	
	// main loop
	while (environment.isRunning()) {
		while (environment.pollEvent() != 0) {
			if (environment.getEvent().type == SDL_QUIT) {
				environment.setRunning(false);
			}
		}
		// clear environment
		environment.setRenderColor(0xFF, 0xFF, 0xFF, 0XFF);
		environment.clear();
		
		// draw rectangle
		environment.setRenderColor(0x00, 0x00, 0x00, 0xFF);
		environment.drawRectangle(environment.getW()/2 - 50, environment.getH()/2 - 50, 100, 100);
		
		// present environment
		environment.present();
	}
	
	// clean up environment
	environment.cleanUp();
}