#pragma once

#include "GameObject.h"

namespace CharacterConstants {
    const int padding = 19;
    const int char_left_inital = 195;
    const int char_width = 52;
    const int char_height = 66;
}

class Game;

class Character :
    public GameObject
{
private:
    sf::Sprite sprite;
    int horizontal_speed;
public:
    Character(Game* game);
    virtual unsigned int GetZIndex() override final;
    virtual const sf::Sprite& GetSprite() override final;
    virtual void UpdateState() override final;
    void SetHorizontalSpeed(int speed);
    int GetHorizontalSpeed();
};

