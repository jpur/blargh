#include "movesystem.h"

void MoveSystem::update(blargh::Entity &entity) {
	Position *p = entity.getComponent<Position>();
	Velocity *v = entity.getComponent<Velocity>();
	p->x += v->x;
	p->y += v->y;
}