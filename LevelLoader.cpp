#include "LevelLoader.h"
#include <fstream>
#include <iostream>

using namespace std;

queue<string>* LevelLoader::load_level(string base_path, string level_name)
{
	queue<string>* objects = new queue<string>();
	
	// ��������� ���� � �������
	string level_path = base_path + level_name + ".txt";
	ifstream level_file;
	level_file.open(level_path);

	// ���������� ��������� ���� � ��������� ������ � �������
	while (!level_file.eof()) {
		string line;
		getline(level_file, line);
		if (line.size() > 0) {
			objects->push(line);
		}
	}

	// ���������
	level_file.close();

	return objects;
}
