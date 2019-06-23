#include "basesystem.h"
#include "event.h"
#include "entity.h"

namespace blargh {
	void BaseSystem::update() {
		for (auto &e : entities) {
			update(*e);
		}
	}

	void BaseSystem::handleMessage(Subject &sender, const Event &event, void *args) {
		if (event == Event::ENTITY_COMPONENT_ADDED || event == Event::ENTITY_COMPONENT_REMOVED) {
			Entity &e = static_cast<Entity &>(sender);
			if (isValid(e)) {
				if ((int)entities.size() <= e.getId()) {
					entities.resize(e.getId()+1);
				}
				entities[e.getId()] = &e;
			}
		}
	}
}