#pragma once

namespace blargh {
	class Observer {
	public:
		void handleMessage(void *msg) = 0;
	}
}