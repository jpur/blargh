#include "component.h"

namespace blargh {
	Component::Component(int entityId) : entityId(entityId) {
		if (components.size() <= entityId) {
			components.resize(entityId+1);
		}
		components[entityId] = this;
	}

	Component::~Component() {
		components[entityId] = nullptr;
	}
}