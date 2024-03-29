#include "basesystem.h"
#include "event.h"
#include "entity.h"

namespace blargh {
	void BaseSystem::update() {
		preupdate();
		for (auto &e : entities) {
			update(*e);
		}
		postupdate();
	}

	void BaseSystem::preupdate() {}
	void BaseSystem::postupdate() {}

	void BaseSystem::handleMessage(Subject &sender, const Event &event, void *args) {
		if (event == Event::ENTITY_COMPONENT_ADDED || event == Event::ENTITY_COMPONENT_REMOVED) {
			// Check if updated entity is valid
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