#include "pch.h"
#include "gameobject.h"
#include "vector2d.h"
#include "simulation.h"

class Map;

class Simulation;

class Creature;

class Food;

class GameObject;

class GameObjectBuilder;

struct Vector2D;


GameObject::GameObject(Simulation * simulation, Vector2D position) :simulation(simulation), position(position) {

}

GameObject::GameObject(Simulation * simulation) : simulation(simulation) {
	isDestroyed = false;
}

char GameObject::getImage() {
	return '?';
}

Vector2D GameObject::getPosition() {
	return position;
}

void GameObject::update() {

}
void GameObject::start() {

}
void GameObject::setPosition(Vector2D position) {
	this->position = position;
}
bool GameObject::isObjectDestroyed() {
	return isDestroyed;
}
void GameObject::destroy() {
	isDestroyed = true;
}