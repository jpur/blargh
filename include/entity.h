#pragma once

#include "subject.h"

namespace blargh {
	class Entity : public Subject {
	public:
		int getId() const;

	private:
		Entity(int id);
		const int id;
	};
}