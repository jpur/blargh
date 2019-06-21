#pragma once

#include "subject.h"

namespace blargh {
	class Entity : public Subject {
	public:
		int getId() const;

		template <class C, typename... Params>
		C &addComponent(Params... params) {
			return C::addComponent(id, params...);
		}

		template <class C>
		C &getComponent() {
			return *C::getComponent(id);
		}

	private:
		Entity(int id);
		const int id;
	};
}