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
		int nextEntityId = 0;
		std::vector<std::unique_ptr<Entity>> entities;
	};
}