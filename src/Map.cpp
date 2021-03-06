#include "pch.h"
#include "map.h"
#include "vector2d.h"
#include "gameobject.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>
#include "Header.h"
#include "creature.h"
#include "simulation.h"

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;
struct Vector2D;

Map::Map() {
	for (auto & row : map) {
		row.fill(nullptr);
	}

}

bool Map::AddGameObjectAt(GameObject* gameObject) {

	Vector2D position = gameObject->getPosition();
	return AddGameObjectAt(gameObject, position.x, position.y);
}

bool Map::AddGameObjectAt(GameObject* gameObject, int positionX, int positionY) {
	GameObject * mapPosition = map[positionX][positionY];
	if (mapPosition == nullptr) {
		map[positionX][positionY] = gameObject;
		gameObjectsForUpdate.push_back(gameObject);
		return true;
	}
	return false;
}

bool Map::MoveGameObjetTo(GameObject & gameObject, int positionX, int positionY) {
	if (positionX >= map.size() || positionY >= map[0].size()) {
		return false;
	}
	if (map[positionX][positionY] != nullptr)
	{
		return false;
	}
	Vector2D currentPosition = gameObject.getPosition();
	map[currentPosition.x][currentPosition.y] = nullptr;
	map[positionX][positionY] = &gameObject;
	gameObject.setPosition(Vector2D(positionX, positionY));

	return true;
}

void Map::update() {
	for (auto & gameObject : gameObjectsForUpdate) {
		gameObject->update();

	}
	//Destroy element 

		//Destroy map elements 
	for (auto & gameObject : gameObjectsForUpdate) {
		if (gameObject->isObjectDestroyed()) {
			RemoveObjectAt(gameObject->getPosition());
		}
	}
	//Destroy updates elements 
	gameObjectsForUpdate.remove_if([](GameObject * gameObject) {return gameObject->isObjectDestroyed(); });
}

void Map::DisplayMap() {
	system("cls");

	std::cout << "-------------------------" << std::endl;

	for (int x = 0; x < map.size(); x++) {
		std::cout << "|";
		for (int y = 0; y < map[x].size(); y++) {
			if (gameObjectExistAt(Vector2D(x, y))) {
				std::cout << map[x][y]->getImage();
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "-------------------------" << std::endl;

	system("Pause");
}

int Map::countCreaturesInMap() {
	int counter = 0;
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if (gameObjectOfTypeExistAt<Creature>(Vector2D(x, y))) {
				counter++;
			}
		}

	}

	return counter;
}