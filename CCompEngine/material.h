#ifndef MATERIAL_H
#define MATERIAL_H

#include "texture.h"
#include "material.h"
#include "Dependencies\glew\glew.h"

typedef struct MaterialData
{
	GLuint ShaderProgramID;
	GLuint* TextureIDs;
} MaterialData;

#endif
