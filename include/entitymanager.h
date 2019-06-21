#pragma once

#include <memory>
#include "subject.h"
#include "entity.h"

namespace blargh {
	class EntityManager : public Subject {
	public:
		std::shared_ptr<Entity> newEntity();
		void destroyEntity(const std::shared_ptr<Entity> &entity);

	private:
		int nextEntityId = 0;
		std::vector<std::shared_ptr<Entity>> entities;
	};
}