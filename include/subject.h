#pragma once

#include <vector>
#include <string>
#include "observer.h"
#include "event.h"

namespace blargh {
	class Observer;

	class Subject {
	public:
		void addObserver(Observer &obs);
		void removeObserver(Observer &obs);
		void notify(const Event &event, void *args);

	private:
		std::vector<Observer *> observers;
	};
}