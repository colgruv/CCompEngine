#ifndef COMPONENT_MAP_H
#define COMPONENT_MAP_H

#include "transform.h"
#include "renderer.h"
#include "list.h"

typedef enum ComponentType
{
	TRANSFORM,
	RENDERER
} ComponentType;

typedef struct ComponentMap
{
	List transforms;
	List renderers;
} ComponentMap;

void *getComponent(unsigned int _actorID, ComponentType _type);

#endif
