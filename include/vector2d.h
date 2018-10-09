#pragma once
#include "pch.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>
#ifndef VECTOR2D_H
#define VECTOR2D_H
#include "vector2d.h"



class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;

struct Vector2D {

	Vector2D(int x, int y);

	Vector2D();
	
	int x;
	
	int y;
};
#endif