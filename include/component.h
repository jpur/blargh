#pragma once

#include <vector>

namespace blargh {
	template <class T>
	class Component {
	public:
		Component(int entityId);

		static bool isAttached(int entityId) {
			return components.size() > entityId && components[entityId] != nullptr;
		}
		
	private:
		static std::vector<Component *> components;
		int entityId;
		
		friend class System;
	}

	template <class T>
	std::vector<Component *> Component<T>::components;
}