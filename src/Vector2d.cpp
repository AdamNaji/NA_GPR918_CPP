#include "pch.h"
#include "vector2d.h"

class Map;
class Simulation;
class Creature;
class Food;
class GameObject;
class GameObjectBuilder;
struct Vector2D;

Vector2D::Vector2D(int x, int y) :x(x), y(y) {

}
Vector2D::Vector2D() {
	x = 0;
	y = 0;
}