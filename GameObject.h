#include <SFML/Graphics/Sprite.hpp>

#pragma once
class GameObject
{
private:
public:
	virtual unsigned int GetZIndex() = 0;
	virtual const sf::Sprite& GetSprite() = 0;
};

