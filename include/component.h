#pragma once

#include <vector>
#include "entity.h"

namespace blargh {
	template <class T>
	class Component {
	public:
		static T &addComponent(int entityId) {
			return *new T(entityId);
		}

		static void removeComponent(int entityId) {
			if (components[entityId] == nullptr) return;
			delete components[entityId];
			components[entityId] = nullptr;
		}

		static T *getComponent(int entityId) {
			if (!isAttached(entityId)) return nullptr;
			return static_cast<T *>(components[entityId]);
		}

		static bool isAttached(int entityId) {
			return (int)components.size() > entityId && components[entityId] != nullptr;
		}

	protected:
		Component(int entityId) : entityId(entityId) {
			if ((int)components.size() <= entityId) {
				components.resize(entityId+1);
			}
			components[entityId] = this;
		}

		~Component() {
			components[entityId] = nullptr;
		}

		const int entityId;

	private:
		static std::vector<Component<T> *> components;
	};

	template <class T>
	std::vector<Component<T> *> Component<T>::components;
}