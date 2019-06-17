#include "entity.h"

namespace blargh {
	Entity::Entity(int id) : id(id) {}

	int Entity::getId() const {
		return id;
	}
}