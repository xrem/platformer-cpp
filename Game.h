#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "GameObject.h"

#pragma once
class Game
{
private:
	bool isPlaying;
	std::map<std::string, sf::Texture> textures;
	std::vector<GameObject*> objects;
public:
	Game();
	void Render(sf::RenderWindow& window);
	void ProcessEvent(const sf::Event& event);
	bool GetIsPlayingStatus();
	const sf::Texture& GetTextureByName(const std::string textureName);
};

