#ifndef ASSET_LIBRARY_H
#define ASSET_LIBRARY_H

#include "material.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"

#include "list.h"

// Main asset ID storage structure
typedef struct AssetLibrary
{
	List meshes;
	List materials;
	List textures;
	List shaders;
} AssetLibrary;


////
// Metadata structures used to organize rendering passes; calculated at initialization to improve runtime performance
////

// ID pair defining presence of any instance in which a particular Mesh uses a particular Shader
typedef struct ShaderMeshPair
{
	unsigned int shaderMeshPairID;
	unsigned int shaderProgramID;
	unsigned int meshID;
} ShaderMeshPair;

void initAssetLibrary(AssetLibrary *_assets);
void loadAssetLibraryManifest(AssetLibrary *_assets, char *_filename);
//int shaderUsesMesh(unsigned int _shaderID, unsigned int _meshID);

#endif
