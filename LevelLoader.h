#include <queue>
#include "GameObject.h"
#include <string>

using namespace std;

#pragma once
class LevelLoader
{
public:
	static queue<string>* load_level(string base_path, string level_name);
};

