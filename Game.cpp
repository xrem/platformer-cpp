#include <string>
#include "Game.h"
#include "Character.h"
#include "Brick.h"

using namespace std;
using namespace sf;

Game::Game()
{
	const string basePath = "C:\\Users\\184321\\Desktop\\Project\\platformer-cpp\\";
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

	srand(NULL);

	// Create objects
	this->character_object = new Character(this);
	this->objects.push_back(this->character_object);
	for (int x = 0; x <= 800; x += 10) {
		this->objects.push_back(new Brick(this, x, rand() % 600));
	}

	this->isPlaying = true;
}

void Game::Render(sf::RenderWindow& window, sf::View& camera)
{
	for (GameObject* object : this->objects) {
		object->UpdateState();
	}
	for (unsigned int zIndex = 0; zIndex <= 3; zIndex++) {
		for (GameObject* object : this->objects) {
			if (object->GetZIndex() == zIndex) {
				window.draw(object->GetSprite());
			}
		}
	}
	Vector2f charPosition = this->character_object->GetSprite().getPosition();
	if (charPosition.x > 650) {
		charPosition.x = 650;
	}
	if (charPosition.x < 150) {
		charPosition.x = 150;
	}
	if (charPosition.y > 500) {
		charPosition.y = 500;
	}
	if (charPosition.y < 100) {
		charPosition.y = 100;
	}
	camera.setCenter(charPosition);
}

void Game::ProcessEvent(const Event& event)
{
	if (event.type == Event::EventType::Closed) {
		this->isPlaying = false;
	}
	if (event.type == Event::EventType::KeyPressed) {
		if (event.key.code == Keyboard::Key::Left) {
			this->character_object->SetHorizontalSpeed(-1);
		}
		if (event.key.code == Keyboard::Key::Right) {
			this->character_object->SetHorizontalSpeed(1);
		}
	}
	if (event.type == Event::EventType::KeyReleased) {
		if (event.key.code == Keyboard::Key::Left 
			&& this->character_object->GetHorizontalSpeed() < 0) {
			this->character_object->SetHorizontalSpeed(0);
		}
		if (event.key.code == Keyboard::Key::Right 
			&& this->character_object->GetHorizontalSpeed() > 0) {
			this->character_object->SetHorizontalSpeed(0);
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
