#include "pch.h"
#include "creature.h"
#include "gameobject.h"
#include "simulation.h"
#include "vector2d.h"
#include "Food.h"
#include "Header.h"

class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;

Creature::Creature(Simulation * simulation, int hungerSpeedIncrement) :GameObject(simulation), hungerSpeedIncrement(hungerSpeedIncrement) {
	hungerPourcent = 0;

}

void Creature::update() {
	if (isDestroyed) {
		return;
	}
	randomMove();

	if (hungerPourcent >= 100) {
		die();
		return;
	}
	Vector2D * foodPosition = &findnearbyFoodPosition();
	if (foodPosition->x >= 0) {

		GameObject & gameObject = simulation->map.getContentAtPosition(*foodPosition);
		if (!gameObject.isObjectDestroyed()) {
			gameObject.destroy();
			hungerPourcent = 0;
		}
	}
	incrementHunger();

	//TODO Implement reproduction method

}

char Creature::getImage() {
	return 'C';
}

Vector2D Creature::findnearbyFoodPosition() {
	Vector2D positionCentral = position;
	for (int x = positionCentral.x - 1; x < positionCentral.x + 3; x++) {
		if (x < 0 || x >= MAP_SIZE) {
			continue;
		}
		for (int y = positionCentral.y - 1; y < positionCentral.y + 3; y++) {
			if (y < 0 || y >= MAP_SIZE) {
				continue;
			}
			Vector2D currentPosition(x, y);
			if (simulation->map.gameObjectOfTypeExistAt<Food>(currentPosition)) {

				return currentPosition;
			}
		}
	}

	return Vector2D(-1, -1);
}

Vector2D Creature::findnearbyCreaturePosition() {
	return Vector2D(0, 0);
}

void Creature::randomMove() {
	int positionXMin = position.x - 1;
	if (positionXMin < 0)
		positionXMin = 0;
	int positionXMax = position.x + 1;
	if (positionXMax >= MAP_SIZE)
		positionXMax = MAP_SIZE - 1;

	int positionYMin = position.y - 1;
	if (positionYMin < 0)
		positionYMin = 0;
	int positionYMax = position.y + 1;
	if (positionYMax >= MAP_SIZE)
		positionYMax = MAP_SIZE - 1;
	int newX = simulation->getValueRandom(positionXMin, positionXMax);
	int newY = simulation->getValueRandom(positionYMin, positionYMax);
	simulation->map.MoveGameObjetTo(*this, newX, newY);
}
void Creature::incrementHunger() {
	hungerPourcent += hungerSpeedIncrement;
}

void Creature::die() {

	isDestroyed = true;
}