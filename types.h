#pragma once
#include <vector>

typedef unsigned int EntityID;
typedef unsigned int ComponentID;
typedef unsigned int MemoryIndex;


typedef struct MemCell{
	EntityID		m_entOwner;	// reference to the entity
	void*			m_comp;		// component data
};

typedef struct FreeMem {
	ComponentID		id;
	MemoryIndex		index;
};

typedef struct CompMemIndex {
	ComponentID		id;
	MemoryIndex		index;
};


typedef struct CompMemCell{
	std::vector<MemCell>	m_components;		// component memory
	unsigned int			m_compSize;			// component size in bytes
	
};

typedef struct Entity {
	std::vector<CompMemIndex>	m_memIndex;		// the index/reference to memory locations
	std::vector<ComponentID>	m_bindedComp;	// the component bound to this entity
	EntityID					m_ID;			// the entity id
};

typedef struct QueryComponent {
	MemCell*			m_compArry;
	unsigned int	m_arryCount;
	unsigned int	m_compSize;
	ComponentID		m_ID;
};