#pragma once

#include "subject.h"
#include "event.h"

namespace blargh {
	class Entity : public Subject {
	public:
		// Returns the ID of this entity
		int getId() const;

		// Attaches the specified component to this entity
		template <class C, typename... Params>
		C &addComponent(Params... params) {
			C &comp = C::addComponent(*this, params...);
			notify(Event::ENTITY_COMPONENT_ADDED, nullptr);
			return comp;
		}	

		// Removes the specified component attached to this entity
		template <class C>
		void removeComponent() {
			C::removeComponent(*this);
			notify(Event::ENTITY_COMPONENT_REMOVED, nullptr);
		}

		// Returns the specificed component attached to this entity
		template <class C>
		C *getComponent() const {
			return C::getComponent(*this);
		}

	private:
		Entity(int id);
		const int id;

		friend class EntityManager;
	};
}