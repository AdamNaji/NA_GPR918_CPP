#pragma once
#include "pch.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>
#ifndef FOOD_H
#define FOOD_H
#include "vector2d.h"
#include "gameobject.h"


class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;


class Food : public GameObject 

{


public:
	Food(Simulation * simulation);

	char getImage();



};
#endif