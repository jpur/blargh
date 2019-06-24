#pragma once

class World {
public:
	World(int width, int height);

	int getWidth() const;
	int getHeight() const;

private:
	const int width;
	const int height;
};