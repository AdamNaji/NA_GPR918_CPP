#pragma once
#include "pch.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>
#ifndef MAP_H
#define MAP_H
#include "vector2d.h"
#include "Header.h"


class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;

class Map {
public:

	Map();

	bool AddGameObjectAt(GameObject* gameObject);

	bool AddGameObjectAt(GameObject* gameObject, int positionX, int positionY);

	GameObject & getContentAtPosition(Vector2D position);

	template<typename T> bool gameObjectOfTypeExistAt(Vector2D position) {
		if (map[position.x][position.y] == nullptr) {
			return false;
		}
		T * gameObject = dynamic_cast<T>(map[position.x][position.y]);
		return gameObject != nullptr;
	}


	bool gameObjectExistAt(Vector2D position);

	bool RemoveObjectAt(Vector2D position);

	bool MoveGameObjetTo(GameObject & gameObject, int positionX, int positionY);

	void update();

	void DisplayMap();

	int countCreaturesInMap();

private:
	std::array<std::array<GameObject, MAP_SIZE>, MAP_SIZE> map;
	std::list<GameObject * > gameObjectsForUpdate;




};
#endif