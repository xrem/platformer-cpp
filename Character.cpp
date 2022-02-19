#include "Character.h"
#include "Game.h"

using namespace sf;
using namespace CharacterConstants;

Character::Character(Game* game)
{
	this->horizontal_speed = 0;
	this->sprite = sf::Sprite(game->GetTextureByName("character"), IntRect(char_left_inital, 16 + padding + char_height, char_width, char_height));
	this->sprite.setScale(0.7, 0.7);
	this->sprite.setPosition(30, 600 - char_height);
}

unsigned int Character::GetZIndex() {
	return 3;
}

const Sprite& Character::GetSprite() {
	return this->sprite;
}

void Character::UpdateState()
{
	this->sprite.move(this->horizontal_speed * 4, 0);
}

void Character::SetHorizontalSpeed(int speed)
{
	this->horizontal_speed = speed;
}

int Character::GetHorizontalSpeed()
{
	return this->horizontal_speed;
}
