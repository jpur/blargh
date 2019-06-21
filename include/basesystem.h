#pragma once

#include <memory>
#include <vector>
#include <string>
#include "subject.h"
#include "entity.h"

namespace blargh {
	class BaseSystem : public Subject, public Observer {
	public:
		System();
		void update();
		void handleMessage(const std::string &msg, void *args);

	protected:
		virtual bool isValid(Entity &entity) = 0;
		virtual void update(Entity &entity) = 0;

	private:
		std::vector<Entity *> entities;
	};
}