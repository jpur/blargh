#include "entitymanager.h"
#include "basesystem.h"
#include "observer.h"

namespace blargh {
	class EntityProcessor : public Observer {
	public:
		EntityProcessor(EntityManager &emgr);

		void registerSystem(BaseSystem &sys);
		void deregisterSystem(BaseSystem &sys);

		void update();
		void handleMessage(Subject &sender, const Event &event, void *args);

	private:
		EntityManager &emgr;
		std::vector<BaseSystem *> systems;
	};
}