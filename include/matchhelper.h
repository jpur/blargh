#pragma once

namespace blargh {
	template<class... Cn> struct MatchHelper;

	// Recursive case 
	template <class C1, class... Cn>
	struct MatchHelper<C1, Cn...> {
		// Returns true if entity contains component of type C1 and remaining types Cn
	    static bool check(const Entity &entity) {
	        return C1::isAttached(entity.getId()) && MatchHelper<Cn...>::check(entity);
	    }
	};

	// Base case
	template <>
	struct MatchHelper<> {
	    static bool check(const Entity &entity) {
	        return true;
	    }
	};
}