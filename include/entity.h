#pragma once

#include "subject.h"
#include "event.h"

namespace blargh {
	class Entity : public Subject {
	public:
		int getId() const;

		template <class C>
		C &addComponent() {
			C &comp = C::addComponent(id);
			notify(Event::ENTITY_COMPONENT_ADDED, nullptr);
			return comp;
		}		

		template <class C>
		void removeComponent() {
			C::removeComponent(id);
			notify(Event::ENTITY_COMPONENT_REMOVED, nullptr);
		}

		template <class C>
		C &getComponent() {
			return *C::getComponent(id);
		}

	private:
		Entity(int id);
		const int id;

		friend class EntityManager;
	};
}