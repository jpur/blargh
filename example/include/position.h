#pragma once

#include "component.h"

class Position : public blargh::Component<Position> {
public:
	Position(int x = 0, int y = 0) : x(x), y(y) {}
	int x, y;
};