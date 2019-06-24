#pragma once

#include <vector>
#include "entity.h"

namespace blargh {
	template <class T>
	class Component {
	public:
		// Attaches a component to an entity
		template <typename... Params>
		static T &addComponent(int entityId, Params... params) {
			if ((int)components.size() <= entityId) {
				components.resize(entityId+1);
			}
			T &comp = components[entityId] = T(params...);
			comp.entityId = entityId;
			comp.attached = true;
			return comp;
		}

		// Removes a component from an entity
		static void removeComponent(int entityId) {
			if (!isAttached(entityId)) return;
			components[entityId].attached = false;
		}

		// Gets a component attached to an entity
		static T *getComponent(int entityId) {
			if (!isAttached(entityId)) return nullptr;
			return &components[entityId];
		}

		// Returns true if the specified component is attached to an entity
		static bool isAttached(int entityId) {
			return (int)components.size() > entityId && components[entityId].attached;
		}

	private:
		// The entity this component is attached to
		int entityId = 1;
		// The attach state of the component
		bool attached = false;

		// Collection of all components of this type; components[k] corresponds to the component attached to entity with id=k
		static std::vector<T> components;
	};

	template <class T>
	std::vector<T> Component<T>::components;
}