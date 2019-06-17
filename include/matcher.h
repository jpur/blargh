#pragma once

#include "entity.h"
#include "matchhelper.h"

namespace blargh {
	template <class... Cn>
	class Matcher {
	public:
		bool matches(const Entity &entity) const {
			return MatchHelper::check<Cn>(entity); 
		}
	}
}