#include "system.h"
#include "events.h"

namespace blargh {
	void System::update() {
		for (auto &e : entities) {
			update(e.get());
		}
	}

	void System::handleMessage(const std::string &msg, void *args) {
		if (msg.compare(E_ENTITY_COMPONENT_ADDED) == 0 || msg.compare(E_ENTITY_COMPONENT_REMOVED) == 0) {
			Entity *e = static_cast<Entity *>(args);
			if (matcher.matches(e)) {
				if (entities.size() <= e.getId()) {
					entities.resize(e.getId()+1);
				}
				entities[e.getId()] = e;
			}
		}
	}
}