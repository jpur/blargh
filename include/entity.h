#pragma once

#include "entitymanager.h"
#include "component.h"

namespace blargh {
	class Entity : public Subject {
	public:
		void addComponent(Component &comp);
		void removeComponent(Component &comp);

		int getId() const;

	private:
		Entity(int id);
		const int id;
	}
}