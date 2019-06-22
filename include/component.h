#pragma once

#include <vector>
#include "entity.h"

namespace blargh {
	#define COMPONENT_INIT void 

	template <class T>
	class Component {
	public:
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

		static void removeComponent(int entityId) {
			if (!isAttached(entityId)) return;
			components[entityId].attached = false;
		}

		static T *getComponent(int entityId) {
			if (!isAttached(entityId)) return nullptr;
			return &components[entityId];
		}

		static bool isAttached(int entityId) {
			return (int)components.size() > entityId && components[entityId].attached;
		}

	private:
		int entityId = 1;
		bool attached = false;
		static std::vector<T> components;
	};

	template <class T>
	std::vector<T> Component<T>::components;
}