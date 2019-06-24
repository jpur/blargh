#pragma once

#include <memory>
#include <algorithm>
#include "entitymanager.h"
#include "basesystem.h"
#include "observer.h"

namespace blargh {
	class EntityProcessor : public Observer {
	public:
		EntityProcessor(EntityManager &emgr);
		
		template <class T, typename... Params>
		const BaseSystem &registerSystem(Params... params) {
			auto sys = std::make_unique<T>(params...);
			systems.push_back(std::move(sys));
			return *sys;
		}

		void deregisterSystem(BaseSystem &sys);
		
		void update();
		void handleMessage(Subject &sender, const Event &event, void *args);

	private:
		EntityManager &emgr;
		std::vector<std::unique_ptr<BaseSystem>> systems;
	};
}