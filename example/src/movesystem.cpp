#include "movesystem.h"

MoveSystem::MoveSystem(int minX, int minY, int maxX, int maxY) : minX(minX), minY(minY), maxX(maxX), maxY(maxY) {}

void MoveSystem::update(blargh::Entity &entity) {
	Position *p = entity.getComponent<Position>();
	Velocity *v = entity.getComponent<Velocity>();

	// Calculate new position
	int newX = p->x + v->x;
	int newY = p->y + v->y;

	// Adjust velocity and position if colliding with boundaries
	if (newX < minX) {
		newX = minX;
		v->x *= -1;
	} else if (newX > maxX) {
		newX = maxX;
		v->x *= -1;
	}
	if (newY < minY) {
		newY = minY;
		v->y *= -1;
	} else if (newY > maxY) {
		newY = maxY;
		v->y *= -1;
	}

	// Set new position
	p->x = newX;
	p->y = newY;
}