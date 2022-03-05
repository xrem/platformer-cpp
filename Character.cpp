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
	// �������� � ������� ���� ��������� ��������
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
	// ���������, � ����� �� �� �� �����.
	this->sprite.move(0, 1);
	for (GameObject* obj : objects) {
		if (Collision::PixelPerfectTest(this->sprite, obj->GetSprite())) {
			// ���� ��, �� ��������������.
			vertical_speed = 0;
			is_on_ground = true;
			break;
		}
	}
	this->sprite.move(0, -1);
	if (!is_on_ground) {
		// �������� �������
		this->vertical_speed += G;
	}
	else if (this->want_to_jump) {
		// �������
		this->vertical_speed = -10 * G;
	}
	this->want_to_jump = false;
	this->sprite.move(this->horizontal_speed * 4, this->vertical_speed);
	for (GameObject* obj : objects) {
		while (Collision::PixelPerfectTest(this->sprite, obj->GetSprite())) {
			// ��������� ��������� �����, ���� �� ���������� � ��������.
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
