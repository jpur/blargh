#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "entitymanager.h"
#include "entityprocessor.h"
#include "movesystem.h"
#include "rendersystem.h"
#include "character.h"

using namespace blargh;

Entity &makeParticle(EntityManager &emgr, int xMin, int yMin, int xMax, int yMax, int maxVel) {
	auto &e = emgr.newEntity();
	e.addComponent<Position>(xMin + rand() % (xMax-xMin), yMin + rand() % (yMax-yMin));
	e.addComponent<Velocity>((rand() % maxVel * 2) - maxVel, (rand() % maxVel * 2) - maxVel);
	e.addComponent<Character>('P');
	return e;
}

int main(void) {
	srand(time(NULL));

	const int worldWidth = 50;
	const int worldHeight = 50;

	EntityManager emgr;
	EntityProcessor eproc(emgr);
	eproc.registerSystem<MoveSystem>(0, 0, worldWidth-1, worldHeight-1);
	eproc.registerSystem<RenderSystem>(worldWidth, worldHeight);

	for (int i = 0; i < 100; i++) {
		makeParticle(emgr, 0, 0, worldWidth, worldHeight, 2);
	}

	while (1) {
		eproc.update();
		Sleep(500);
	}

	return 0;
}