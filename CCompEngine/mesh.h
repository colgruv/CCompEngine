#ifndef MESH_H
#define MESH_H

#include "Dependencies\glew\glew.h"

typedef struct MeshData
{
	char* Name;
	unsigned int AssetID;

	GLuint VertexBufferID;
	GLuint NormalBufferID;
	GLuint UVBufferID;
} MeshData;

MeshData primitiveCube();

#endif
