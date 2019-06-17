#pragma once

namespace blargh {
	template<class... Cn> struct MatchHelper;

	template <class C1, class... Cn>
	struct MatchHelper<C1, Cn...> {
	    static bool check(const Entity &entity) {
	        return C1::isAttached(entity.getId()) && MatchHelper<Cn...>::check(entity);
	    }
	};

	template <>
	struct MatchHelper<> {
	    static bool check(const Entity &entity) {
	        return true;
	    }
	};
}