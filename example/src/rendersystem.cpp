#include <iostream>
#include <string.h>
#include "rendersystem.h"

RenderSystem::RenderSystem(int width, int height) : width(width), height(height) {
	screen = new char[width * height];
}

RenderSystem::~RenderSystem() {
	delete[] screen;
}

bool RenderSystem::isVisible(const blargh::Entity &entity) {
	Position *p = entity.getComponent<Position>();
	return p->x >= 0 && p->x < width && p->y >= 0 && p->y < height;
}

void RenderSystem::preupdate() {
	// Reset screen
	memset(screen, '-', width * height);
}

void RenderSystem::update(blargh::Entity &entity) {
	// Not drawing if it's out of bounds
	if (!isVisible(entity)) return;

	// Draw tos creen
	Position *p = entity.getComponent<Position>();	
	Character *chr = entity.getComponent<Character>();
	screen[p->y * width + p->x] = chr->character;
}

void RenderSystem::postupdate() {
	// Print screen
	std::cout << std::endl;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::cout << screen[y * width + x] << " ";
		}
		std::cout << std::endl;
	}
}