#include <iostream>
#include "entitymanager.h"
#include "entityprocessor.h"
#include "movesystem.h"
#include "basesystem.h"
#include "rendersystem.h"
#include "world.h"
#include "character.h"

using namespace blargh;

int main(void) {
	EntityManager emgr;
	EntityProcessor eproc(emgr);
	eproc.registerSystem<MoveSystem>();
	eproc.registerSystem<RenderSystem>(50, 50);

	auto e = emgr.newEntity();

	e.addComponent<Position>(10, 10);
	e.addComponent<Velocity>(3, 1);
	e.addComponent<Character>('A');

	for (int i = 0; i < 3; i++) {
		eproc.update();
	}

	return 0;
}