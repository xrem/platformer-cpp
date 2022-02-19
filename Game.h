#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "GameObject.h"
#include "Character.h"

class Game
{
private:
	bool isPlaying;
	std::map<std::string, sf::Texture> textures;
	std::vector<GameObject*> objects;
	Character* character_object;
public:
	Game();
	void Render(sf::RenderWindow& window, sf::View& camera);
	void ProcessEvent(const sf::Event& event);
	bool GetIsPlayingStatus();
	const sf::Texture& GetTextureByName(const std::string textureName);
};

