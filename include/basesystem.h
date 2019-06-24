#pragma once

#include <memory>
#include <vector>
#include <string>
#include "subject.h"
#include "entity.h"

namespace blargh {
	class BaseSystem : public Subject, public Observer {
	public:
		virtual ~BaseSystem() = default;
		
		// Updates over all valid entities
		void update();
		void handleMessage(Subject &sender, const Event &event, void *args);

	protected:
		// Returns true if the system should update this entity
		virtual bool isValid(Entity &entity) = 0;
		
		// Updates a valid entity
		virtual void update(Entity &entity) = 0;

	private:
		// Holds all valid entities
		std::vector<Entity *> entities;
	};
}