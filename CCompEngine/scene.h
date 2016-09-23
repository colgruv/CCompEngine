#ifndef SCENE_H
#define SCENE_H

#include "actor.h"
#include "list.h"

typedef struct SceneMap
{
	ActorData root;
	List actorList;
} SceneMap;

#endif
