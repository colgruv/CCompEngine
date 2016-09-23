#ifndef RENDERER_H
#define RENDERER_H

#include "Dependencies\glew\glew.h"
#include "Dependencies\glm\glm.hpp"

typedef struct TransformComponent
{
	glm::vec3 position;
	glm::vec4 rotation;
	glm::vec3 eulerAngles;
	glm::vec3 scale;
} TransformComponent;

#endif