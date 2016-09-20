#ifndef ASSET_LIBRARY_H
#define ASSET_LIBRARY_H

#include "material.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"

#include "list.h"

typedef struct AssetLibrary
{
	List Meshes;
	List Materials;
	List Textures;
	List Shaders;
} AssetLibrary;

#endif
