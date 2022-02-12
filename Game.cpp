#include <string>
#include "Game.h"
#include "Character.h"

using namespace std;
using namespace sf;

Game::Game()
{
	const string basePath = "C:\\Users\\XAdmin\\source\\repos\\PlatformerCPP\\";
	// Initialize
	map<string, string> textureToLoad = {
		{ "world", "объекты.png" },
		{ "background", "фоновое изображение.png" },
		{ "character", "персонаж.png" }
	};
	for (pair<string, string> texturePair : textureToLoad) {
		Texture texture;
		if (!texture.loadFromFile(basePath + texturePair.second)) {
			throw exception("Cannot load texture files!");
		}
		this->textures.insert(pair<string, Texture>(texturePair.first, texture));
	}

	// Create objects
	this->objects.push_back(new Character(this));

	this->isPlaying = true;
}

void Game::Render(sf::RenderWindow& window)
{
	for (unsigned int zIndex = 0; zIndex <= 3; zIndex++) {
		for (GameObject* object : this->objects) {
			if (object->GetZIndex() == zIndex) {
				window.draw(object->GetSprite());
			}
		}
	}
}

void Game::ProcessEvent(const Event& event)
{
	if (event.type == Event::EventType::Closed) {
		this->isPlaying = false;
	}
	if (event.type == Event::EventType::KeyPressed) {
		if (event.key.code == Keyboard::Key::Left) {
			// horizontal_speed = -1;
		}
		if (event.key.code == Keyboard::Key::Right) {
			// horizontal_speed = 1;
		}
	}
	if (event.type == Event::EventType::KeyReleased) {
		if (event.key.code == Keyboard::Key::Left /* && horizontal_speed < 0 */) {
			// horizontal_speed = 0;
		}
		if (event.key.code == Keyboard::Key::Right /* && horizontal_speed > 0 */) {
			// horizontal_speed = 0;
		}
	}
}

bool Game::GetIsPlayingStatus()
{
    return this->isPlaying;
}

const sf::Texture& Game::GetTextureByName(std::string textureName)
{
	return this->textures[textureName];
}
