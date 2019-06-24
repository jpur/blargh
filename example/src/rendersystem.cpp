#include <iostream>
#include <string.h>
#include "rendersystem.h"
#include "character.h"

RenderSystem::RenderSystem(int width, int height) : width(width), height(height) {
	screen = new char[width * height];
}

RenderSystem::~RenderSystem() {
	delete[] screen;
}

void RenderSystem::preupdate() {
	memset(screen, '-', width * height);
}

void RenderSystem::update(blargh::Entity &entity) {
	Position *p = entity.getComponent<Position>();	
	Character *chr = entity.getComponent<Character>();

	screen[p->y * width + p->x] = chr->character;
}

void RenderSystem::postupdate() {
	std::cout << std::endl;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::cout << screen[y * width + x] << " ";
		}
		std::cout << std::endl;
	}
}