#pragma once
#include "pch.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>
#ifndef CREATURE_H
#define CREATURE_H
#include "vector2d.h"
#include "gameobject.h"


class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;

class Creature : public GameObject

{

public:

	Creature(Simulation * simulation, int hungerSpeedIncrement);

	void update();
	char getImage();


private:

	int hungerPourcent;
	int hungerSpeedIncrement = 20;

	//Return position. If food is not find, we return the value (-1,-1)
	Vector2D findnearbyFoodPosition();

	//Return position. If creature is not find, we return the value (-1,-1)
	Vector2D findnearbyCreaturePosition();



	void randomMove();
	void incrementHunger();
	void die();

};

#endif
