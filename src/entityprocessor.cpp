#include "entityprocessor.h"

namespace blargh {
	EntityProcessor::EntityProcessor(EntityManager &emgr) : emgr(emgr) {

	}

	void EntityProcessor::registerSystem(BaseSystem &sys) {

	}
	
	void EntityProcessor::deregisterSystem(BaseSystem &sys) {

	}

	void EntityProcessor::handleMessage(Subject &sender, const Event &event, const void *args) {

	}
}