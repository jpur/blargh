#pragma once

#include <string.h>

namespace blargh {
	class Observer {
	public:
		void handleMessage(const std::string &msg, void *args) = 0;
	}
}