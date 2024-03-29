#pragma once
#include "Types.h"
#include <queue>
class EntityManager {
	
public:

	becs::EntityID registerEntity(bool* isThisRealloc);
	bool doesExist(becs::EntityID entID);
	void bindComponentToEnt(becs::EntityID entID, becs::ComponentID compID);
	void unbindAllComponents(becs::EntityID entID);
	void unregisterEntity(becs::EntityID entID);
	size_t getEntityCapacity();
	size_t getEntityCount();

	const std::vector<becs::ComponentID>& getComponentBounded(becs::EntityID entID);
	
private:
	
	becs::EntityID m_counter = 0;
	std::vector<becs::Entity> m_entities;
	std::vector<bool> m_isActive;
	std::queue<becs::EntityID> m_deletedEnt;
	
};

