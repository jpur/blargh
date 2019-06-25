#pragma once

#include "system.h"
#include "position.h"
#include "velocity.h"
#include "entity.h"

class MoveSystem : public blargh::System<Position, Velocity> {
public:
	MoveSystem(int minX, int minY, int maxX, int maxY);

protected:
	void update(blargh::Entity &entity);

private:
	int minX, minY;
	int maxX, maxY;
};