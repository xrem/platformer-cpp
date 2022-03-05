#include "LevelLoader.h"
#include <fstream>
#include <iostream>

using namespace std;

queue<string>* LevelLoader::load_level(string base_path, string level_name)
{
	queue<string>* objects = new queue<string>();
	
	// Открываем файл с уровнем
	string level_path = base_path + level_name + ".txt";
	ifstream level_file;
	level_file.open(level_path);

	// Вычитывает построчно файл и сохраняем строки в очередь
	while (!level_file.eof()) {
		string line;
		getline(level_file, line);
		if (line.size() > 0) {
			objects->push(line);
		}
	}

	// Закрываем
	level_file.close();

	return objects;
}
