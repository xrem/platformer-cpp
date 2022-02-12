#pragma once

#include "GameObject.h"
#include "Game.h"

namespace CharacterConstants {
    const int padding = 19;
    const int char_left_inital = 195;
    const int char_width = 52;
    const int char_height = 66;
}

class Character :
    public GameObject
{
private:
    sf::Sprite sprite;
public:
    Character(Game* game);
    virtual unsigned int GetZIndex() override final;
    virtual const sf::Sprite& GetSprite() override final;
};

