#pragma once

#include <vector>
#include "entity.h"

namespace blargh {
	template <class T>
	class Component {
	public:
		template <typename... Params>
		static T *addComponent(int entityId, Params... params) {
			return new T(entityId, params...);
		}

		static void removeComponent(int entityId) {
			if (components[entityId] == nullptr) return;
			delete components[entityId];
			components[entityId] = nullptr;
		}


		static T *getComponent(int entityId) {
			if (!isAttached(entityId)) return nullptr;
			return components[entityId];
		}

		static bool isAttached(int entityId) {
			return (int)components.size() > entityId && components[entityId] != nullptr;
		}

	private:
		Component(int entityId) : entityId(entityId) {
			if (components.size() <= entityId) {
				components.resize(entityId+1);
			}
			components[entityId] = this;
		}

		~Component() {
			components[entityId] = nullptr;
		}

		static std::vector<T *> components;
		int entityId;
	};

	template <class T>
	std::vector<T *> Component<T>::components;
}