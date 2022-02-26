#include <SFML/Graphics/Sprite.hpp>
#include <vector>

#pragma once

class GameObject
{
private:
public:
	virtual unsigned int GetZIndex() = 0;
	virtual const sf::Sprite& GetSprite() = 0;
	virtual void UpdateState(const std::vector<GameObject*>& objects) = 0;
};

