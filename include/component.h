#pragma once

#include <vector>
#include "entity.h"
#include "observer.h"

namespace blargh {
	template <class T>
	class Component : public Observer {
	public:
		// Attaches a component to an entity
		template <typename... Params>
		static T &addComponent(Entity &entity, Params... params) {
			int eid = entity.getId();
			if ((int)components.size() <= eid) {
				components.resize(eid+1);
			}
			T &comp = components[eid] = T(params...);
			comp.entityId = eid;
			comp.attached = true;
			entity.addObserver(comp);
			return comp;
		}

		// Removes a component from an entity
		static void removeComponent(Entity &entity) {
			if (!isAttached(entity)) return;
			components[entity.getId()].attached = false;
		}

		// Gets a component attached to an entity
		static T *getComponent(const Entity &entity) {
			if (!isAttached(entity)) return nullptr;
			return &components[entity.getId()];
		}

		// Returns true if the specified component is attached to an entity
		static bool isAttached(const Entity &entity) {
			int eid = entity.getId();
			return (int)components.size() > eid && components[eid].attached;
		}
		
		void handleMessage(Subject &sender, const Event &event, void *args) {
			if (event == Event::ENTITY_DESTROY) {
				components[entityId].attached = false;
			}
		}

	private:
		// The entity this component is attached to
		int entityId = -1;
		// The attach state of the component
		bool attached = false;

		// Collection of all components of this type; components[k] corresponds to the component attached to entity with id=k
		static std::vector<T> components;
	};

	template <class T>
	std::vector<T> Component<T>::components;
}