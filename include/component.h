#pragma once

#include <vector>

namespace blargh {
	template <class T>
	class Component {
	public:
		Component(int entityId) : entityId(entityId) {
			if (components.size() <= entityId) {
				components.resize(entityId+1);
			}
			components[entityId] = this;
		}

		~Component() {
			components[entityId] = nullptr;
		}

		static bool isAttached(int entityId) {
			return components.size() > entityId && components[entityId] != nullptr;
		}
		
	private:
		static std::vector<Component *> components;
		int entityId;
		
		friend class BaseSystem;
	};

	template <class T>
	std::vector<Component<T> *> Component<T>::components;
}