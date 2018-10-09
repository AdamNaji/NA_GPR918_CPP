#include "pch.h"
#include "simulation.h"
#include "gameobject.h"
#include "gameobjectbuilder.h"
#include <array>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <list>


class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;

void Simulation::init() {
	//Create 5 creatures 
	for (int i = 0; i < 5; i++) {
		map.AddGameObjectAt((GameObject)GameObjectBuilder::buildCreature(this));
	}

	//Create 6 foods 
	for (int i = 0; i < 6; i++) {
		map.AddGameObjectAt((GameObject)GameObjectBuilder::buildFood(this));
	}

}

void Simulation::star() {
	while (!isEndSimulation()) {
		update();
		map.DisplayMap();
	}
	std::cout << std::endl << "------ END OF SIMULATION -------------" << std::endl;
	system("Pause");
}

int Simulation::getValueRandom(int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	int randomValue = distribution(random);
	return randomValue;
}

void Simulation::update() {

	map.update();


}

bool Simulation::isEndSimulation() {
	return map.countCreaturesInMap() <= 0;
}