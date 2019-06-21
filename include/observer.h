#pragma once

#include <string>

namespace blargh {
	class Observer {
	public:
		virtual void handleMessage(const std::string &msg, void *args) = 0;
	};
}