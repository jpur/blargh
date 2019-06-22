#pragma once

#include <string>
#include "subject.h"
#include "event.h"

namespace blargh {
	class Subject;
	class Observer {
	public:
		virtual void handleMessage(Subject &sender, const Event &event, const void *args) = 0;
	};
}