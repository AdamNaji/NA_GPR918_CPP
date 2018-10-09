#include "pch.h"
#include "gameobjectbuilder.h"
#include "Food.h"
#include "vector2d.h"
#include "Simulation.h"
#include "Creature.h"
#include "GameObject.h"
#include "Header.h"

class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;


Food * GameObjectBuilder::buildFood(Simulation & simulation) {
	Food* food = new Food(&simulation);
	int x = simulation.getValueRandom(0, MAP_SIZE - 1);
	int y = simulation.getValueRandom(0, MAP_SIZE - 1);
	food->setPosition(Vector2D(x, y));
	return food;
}

Creature *  GameObjectBuilder::buildCreature(Simulation & simulation) {
	Creature* creature = new Creature(&simulation, 20);
	int x = simulation.getValueRandom(0, MAP_SIZE - 1);
	int y = simulation.getValueRandom(0, MAP_SIZE - 1);
	creature->setPosition(Vector2D(x, y));
	return creature;


}