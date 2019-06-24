#pragma once

#include <string>
#include "component.h"

class Character : public blargh::Component<Character> {
public:
	Character(char character = 0) : character(character) {}
	char character;
};