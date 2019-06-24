#pragma once

#include <memory>
#include "subject.h"
#include "entity.h"

namespace blargh {
	class EntityManager : public Subject {
	public:
		Entity &newEntity();
		void destroyEntity(Entity &entity);

	protected:
		int getNextEntityId();

	private:
		// The next valid entity ID
		int nextEntityId = 0;
		// Stores created entities
		std::vector<std::unique_ptr<Entity>> entities;
	};
}