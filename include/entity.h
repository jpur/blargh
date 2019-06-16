#pragma once

#include "entitymanager.h"
#include "component.h"

namespace blargh {
	class Entity : public Subject {
	public:
		void addComponent(Component comp);
		void removeComponent(Component comp);

	private:
		Entity() = default;
		long id;
		std::vector<Component> components;
		friend class EntityManager;
	}
}