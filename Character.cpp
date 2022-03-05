#include "Character.h"
#include "Game.h"
#include "Collision.h"

using namespace sf;
using namespace CharacterConstants;

Character::Character(Game* game, float x, float y)
{
	this->want_to_jump = false;
	this->horizontal_speed = 0;
	this->vertical_speed = 0;
	this->sprite = sf::Sprite(game->GetTextureByName("character"), IntRect(char_left_inital, 16 + padding + char_height, char_width, char_height));
	this->sprite.setScale(0.7, 0.7);
	this->sprite.setPosition(x, y);
}

unsigned int Character::GetZIndex() {
	return 3;
}

const Sprite& Character::GetSprite() {
	return this->sprite;
}

void Character::UpdateState(const std::vector<GameObject*>& objects)
{
	/*
	// Покраска в красный если произошла коллизия
	bool collides = false;
	for (GameObject* obj : objects) {
		if (Collision::PixelPerfectTest(this->sprite, obj->GetSprite())) {
			collides = true;
			break;
		}
	}
	IntRect textureRect = this->sprite.getTextureRect();
	if (collides) {
		textureRect.left = 269;
		textureRect.top = 390;
	}
	else {
		textureRect.left = char_left_inital;
		textureRect.top = 16 + padding + char_height;
	}
	this->sprite.setTextureRect(textureRect);
	*/
	bool is_on_ground = false;
	// Проверяем, в стоим ли мы на земле.
	this->sprite.move(0, 1);
	for (GameObject* obj : objects) {
		if (Collision::PixelPerfectTest(this->sprite, obj->GetSprite())) {
			// Если да, то остнавливаемся.
			vertical_speed = 0;
			is_on_ground = true;
			break;
		}
	}
	this->sprite.move(0, -1);
	if (!is_on_ground) {
		// Ускоряем падение
		this->vertical_speed += G;
	}
	else if (this->want_to_jump) {
		// Прыгаем
		this->vertical_speed = -10 * G;
	}
	this->want_to_jump = false;
	this->sprite.move(this->horizontal_speed * 4, this->vertical_speed);
	for (GameObject* obj : objects) {
		while (Collision::PixelPerfectTest(this->sprite, obj->GetSprite())) {
			// Выталкием персонажа вверх, если он впечатался в текстуру.
			this->sprite.move(0, -1);
		}
	}
}

void Character::SetHorizontalSpeed(int speed)
{
	this->horizontal_speed = speed;
}

int Character::GetHorizontalSpeed()
{
	return this->horizontal_speed;
}

void Character::TryToJump() {
	this->want_to_jump = true;
}
