#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

const int screen_width = 800;
const int screen_height = 600;
const int FPS = 15;
const int padding = 19;
const int char_left_inital = 195;
const int char_width = 52;
const int char_height = 66;
const float delay = 1000 / FPS;
int horizontal_speed = 0;

int WinMain() {
	Game game;
	RenderWindow window(VideoMode(screen_width, screen_height), "Platformer game");
	View camera(FloatRect(
		0.f, // ?????????? ????? ?????
		screen_height / 3.0f * 2.0f, // ?????????? ?????? ?????
		screen_width / 3.0f, // ??????
		screen_height / 3.0f)); // ??????
	// TODO: Move to game;
	Clock clock;

	Sprite background(game.GetTextureByName("background"));

	while (game.GetIsPlayingStatus() == true) {
		Event event;
		while (window.pollEvent(event)) {
			game.ProcessEvent(event);
		}

		if (clock.getElapsedTime().asMilliseconds() < delay) {
			continue;
		}
		else {
			clock.restart();
		}

		// TODO: Move to character;
		/*
		// ???????? ?????????
		IntRect charRect = character.getTextureRect();
		charRect.left += char_width + padding;
		if (charRect.left >= char_left_inital + (6 * (char_width + padding))) {
			charRect.left = char_left_inital;
		}
		// ???????? ?????????
		if ((horizontal_speed < 0 && charRect.width > 0) || (horizontal_speed > 0 && charRect.width < 0)) {
			charRect.width = -charRect.width;
		}
		character.setTextureRect(charRect);

		character.move(horizontal_speed * 4, 0);
		*/

		window.draw(background);
		game.Render(window, camera);
		window.setView(camera);
		window.display();
	}

	window.close();
	return 0;
}