#include "pch.h"
#include "Food.h"
#include "gameobject.h"
#include "simulation.h"

class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;

Food::Food(Simulation * simulation) :GameObject(simulation) {

}

char Food::getImage() {
	return 'F';
}