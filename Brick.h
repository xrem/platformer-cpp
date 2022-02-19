#pragma once
#include "GameObject.h"

class Game;

class Brick :
	public GameObject
{
private:
	sf::Sprite sprite;
public:
	Brick(Game* game, float x, float y);
	virtual unsigned int GetZIndex() override final;
	virtual const sf::Sprite& GetSprite() override final;
	virtual void UpdateState() override final;
};

