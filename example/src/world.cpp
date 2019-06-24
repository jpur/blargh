#include "world.h"
#include <iostream>

World::World(int width, int height) : width(width), height(height) {
}

int World::getWidth() const {
	return width;
}

int World::getHeight() const {
	return height;
}