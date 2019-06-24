#pragma once

#include "system.h"
#include "position.h"
#include "velocity.h"
#include "entity.h"

class MoveSystem : public blargh::System<Position, Velocity> {
protected:
	void update(blargh::Entity &entity);
};