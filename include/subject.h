#pragma once

#include "observer.h"

namespace blargh {
	class Subject {
	public:
		void addObserver(Observer &obs);
		void removeObserver(Observer &obs);
		void notify(void *msg);

	private:
		std::vector<Observer *> observers;
	}
}