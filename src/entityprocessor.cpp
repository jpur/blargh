#include "entityprocessor.h"
#include "event.h"

namespace blargh {
	EntityProcessor::EntityProcessor(EntityManager &emgr) : emgr(emgr) {
		emgr.addObserver(*this);
	}

	void EntityProcessor::registerSystem(BaseSystem &sys) {
		systems.push_back(&sys);
	}
	
	void EntityProcessor::deregisterSystem(BaseSystem &sys) {
	}

	void EntityProcessor::update() {
		for (auto &sys : systems) {
			sys->update();	
		}
	}

	void EntityProcessor::handleMessage(Subject &sender, const Event &event, void *args) {
		if (event == Event::ENTITY_NEW) {
			// Listen to events of new entity
			Entity *entity = static_cast<Entity *>(args);
			entity->addObserver(*this);
		} else if (event == Event::ENTITY_COMPONENT_ADDED || event == Event::ENTITY_COMPONENT_REMOVED) {
			// Pass on event to registered systems
			for (auto &sys : systems) {
				sys->handleMessage(sender, event, args);
			}
		}
	}
}