#include "basesystem.h"
#include "events.h"
#include "entity.h"

namespace blargh {
	void BaseSystem::update() {
		for (auto &e : entities) {
			update(*e);
		}
	}

	void BaseSystem::handleMessage(const std::string &msg, void *args) {
		if (msg.compare(E_ENTITY_COMPONENT_ADDED) == 0 || msg.compare(E_ENTITY_COMPONENT_REMOVED) == 0) {
			Entity *e = static_cast<Entity *>(args);
			if (isValid(*e)) {
				if ((int)entities.size() <= e->getId()) {
					entities.resize(e->getId()+1);
				}
				entities[e->getId()] = e;
			}
		}
	}
}