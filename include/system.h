#pragma once

#include <memory>
#include <vector>
#include "subject.h"

namespace blargh {
	class System : public Subject {
	public:
		void update();

	private:
		std::vector<std::shared_ptr<Entity>> entities;
	}
}