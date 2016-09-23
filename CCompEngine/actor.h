#ifndef ACTOR_H
#define ACTOR_H

typedef struct ActorData
{
	// Actor Heading
	char* name;
	unsigned int actorID;
	bool isActive;

	// Node Navigation Information
	ActorData* next;
	ActorData* firstChild;
} ActorData;

#endif
