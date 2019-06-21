#pragma once

#include <memory>
#include <vector>
#include <string.h>
#include "basesystem.h"
#include "matcher.h"

namespace blargh {
	template <class... Tn>
	class System : public BaseSystem {
	public:
		System(const Matcher<Tn...> &matcher);

	protected:
		virtual bool isValid(Entity &entity) {
			return matcher.matches(entity);
		}

	private:
		const Matcher<Tn...> matcher;
	};
}