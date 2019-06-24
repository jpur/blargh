#pragma once

#include "component.h"

class Velocity : public blargh::Component<Velocity> {
public:
	Velocity(int x = 0, int y = 0) : x(x), y(y) {}
	int x, y;
};