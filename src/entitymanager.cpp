#include "entitymanager.h"

namespace blargh {
	Entity &EntityManager::newEntity() {
		int id = getNextEntityId();
		Entity *entity = new Entity(id);
		entities.push_back(std::unique_ptr<Entity>(entity));
		notify(Event::ENTITY_NEW, entity);
		return *entity;
	}

	void EntityManager::destroyEntity(Entity &entity) {
		notify(Event::ENTITY_DESTROY, &entity);
		entities[entity.getId()] = nullptr;
	}

	int EntityManager::getNextEntityId() {
		return nextEntityId++;
	}
}