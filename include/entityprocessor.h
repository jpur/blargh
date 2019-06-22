#include "entitymanager.h"
#include "basesystem.h"
#include "observer.h"

namespace blargh {
	class EntityProcessor : public Observer {
	public:
		EntityProcessor(EntityManager &emgr);

		void registerSystem(BaseSystem &sys);
		void deregisterSystem(BaseSystem &sys);

		void handleMessage(Subject &sender, const Event &event, const void *args);

	private:
		EntityManager &emgr;
	};
}