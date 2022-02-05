#include <SFML/Graphics.hpp>

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
	RenderWindow window(VideoMode(screen_width, screen_height), "Platformer game");
	Clock clock;
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("C:\\Users\\XAdmin\\source\\repos\\PlatformerCPP\\фоновое изображение.png");
	Texture characterMap;
	characterMap.loadFromFile("C:\\Users\\XAdmin\\source\\repos\\PlatformerCPP\\персонаж.png");
	Sprite background(backgroundTexture);
	Sprite character(characterMap, IntRect(char_left_inital, 16 + padding + char_height, char_width, char_height));
	character.setPosition(30, screen_height - char_height);


	bool isPlaying = true;
	while (isPlaying) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::EventType::Closed) {
				isPlaying = false;
			}
			if (event.type == Event::EventType::KeyPressed) {
				if (event.key.code == Keyboard::Key::Left) {
					horizontal_speed = -1;
				}
				if (event.key.code == Keyboard::Key::Right) {
					horizontal_speed = 1;
				}
			}
			if (event.type == Event::EventType::KeyReleased) {
				if (event.key.code == Keyboard::Key::Left && horizontal_speed < 0) {
					horizontal_speed = 0;
				}
				if (event.key.code == Keyboard::Key::Right && horizontal_speed > 0) {
					horizontal_speed = 0;
				}
			}
		}

		if (clock.getElapsedTime().asMilliseconds() < delay) {
			continue;
		}
		else {
			clock.restart();
		}

		// Анимация персонажа
		IntRect charRect = character.getTextureRect();
		charRect.left += char_width + padding;
		if (charRect.left >= char_left_inital + (6 * (char_width + padding))) {
			charRect.left = char_left_inital;
		}
		// Разворот персонажа
		if ((horizontal_speed < 0 && charRect.width > 0) || (horizontal_speed > 0 && charRect.width < 0)) {
			charRect.width = -charRect.width;
		}
		character.setTextureRect(charRect);

		character.move(horizontal_speed * 4, 0);

		window.draw(background);
		window.draw(character);
		window.display();
	}

	window.close();
	return 0;
}