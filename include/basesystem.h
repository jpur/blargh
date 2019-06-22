#pragma once

#include <memory>
#include <vector>
#include <string>
#include "subject.h"
#include "entity.h"

namespace blargh {
	class BaseSystem : public Subject, public Observer {
	public:
		void update();
		void handleMessage(Subject &sender, const Event &event, const void *args);

	protected:
		virtual bool isValid(Entity &entity) = 0;
		virtual void update(Entity &entity) = 0;

	private:
		std::vector<Entity *> entities;
	};
}