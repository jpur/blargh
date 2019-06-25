#pragma once

#include "system.h"
#include "position.h"
#include "velocity.h"
#include "entity.h"
#include "character.h"

class RenderSystem : public blargh::System<Position, Character> {
public:
	RenderSystem(int width, int height);
	~RenderSystem();

protected:
	void preupdate();
	void update(blargh::Entity &entity);
	void postupdate();

private:
	bool isVisible(const blargh::Entity &entity);

	const int width;
	const int height;
	char *screen;
};