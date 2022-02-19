#include "Brick.h"
#include "Game.h"

using namespace sf;

Brick::Brick(Game* game, float x, float y)
{
	this->sprite = Sprite(game->GetTextureByName("world"), IntRect(81, 1, 14, 14));
	this->sprite.setPosition(x, y);
}

unsigned int Brick::GetZIndex()
{
	return 3;
}

const sf::Sprite& Brick::GetSprite()
{
	return this->sprite;
}

void Brick::UpdateState()
{
	// Does nothing
}
