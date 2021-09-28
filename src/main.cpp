#include "Game.hpp"

#define FPS 30
#define FRAME_DELAY 1000 / FPS

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

	Uint32 frame_start;
	int frame_time;
	
	Game::Instance()->init("Touhou Game", 1280, 720);

	while (Game::Instance()->running()) {
		frame_start = SDL_GetTicks();

		Game::Instance()->handle_events();
		Game::Instance()->update();
		Game::Instance()->render();

		frame_time = SDL_GetTicks() - frame_start;
		if (FRAME_DELAY > frame_time) {
			SDL_Delay(FRAME_DELAY - frame_time);
		}
	}
	return 0;
}