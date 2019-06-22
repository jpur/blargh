#pragma once

#include <memory>
#include <vector>
#include <string.h>
#include "basesystem.h"
#include "matcher.h"

namespace blargh {
	template <class... Tn>
	class System : public BaseSystem {
	protected:
		bool isValid(Entity &entity) {
			return matcher.matches(entity);
		}

	private:
		Matcher<Tn...> matcher;
	};
}