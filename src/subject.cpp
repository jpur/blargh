#include <algorithm>
#include "subject.h"
#include "event.h"

namespace blargh {
	void Subject::addObserver(Observer &obs) {
		observers.push_back(&obs);
	}

	void Subject::removeObserver(Observer &obs) {
		auto it = std::find(observers.begin(), observers.end(), &obs);
		if (it != observers.end()) {
			observers.erase(it);
		}
	}

	void Subject::notify(const Event &event, const void *args) {
		for (auto &obs : observers) {
			obs->handleMessage(*this, event, args);
		}
	}
}