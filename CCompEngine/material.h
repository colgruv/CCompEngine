#ifndef MATERIAL_H
#define MATERIAL_H

#include "Dependencies\glew\glew.h"

typedef struct MaterialData
{
	char* Name;
	unsigned int AssetID;
	GLuint ShaderProgramID;
	GLuint DiffuseTextureID;
	GLuint NormalTextureID;
	GLuint SpecularTextureID;
} MaterialData;

#endif
