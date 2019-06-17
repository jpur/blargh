#pragma once

#include <memory>
#include <vector>
#include <string.h>
#include "subject.h"

namespace blargh {
	class System : public Subject, public Observer {
	public:
		System(const Matcher &matcher);
		void update();
		void handleMessage(const std::string &msg, void *args);

	protected:
		virtual void update(Entity &entity) = 0;

	private:
		const Matcher matcher;
		std::vector<Entity *> entities;
	}
}