#include "asset_library.h"

// Initialize Asset Library and load default values
void initAssetLibrary(AssetLibrary *_assets)
{
	// Load shader
	GLuint programID = LoadShaders("Assets//Shaders//TransformVertexShader.vertexshader", "Assets//Shaders//TextureFragmentShader.fragmentshader");
	ShaderData shader;
	shader.ShaderProgramID = programID;
	shader.Name = "DefaultShader";
	shader.AssetID = 0;
	list_init(&_assets->shaders);
	list_add(&_assets->shaders, &shader);

	// Load texture
	GLuint TextureID = loadDDS("Assets//Textures//uvtemplate.DDS");
	TextureData texture;
	texture.TextureID = TextureID;
	texture.Name = "untemplate";
	texture.AssetID = 0;
	list_init(&_assets->textures);
	list_add(&_assets->textures, &texture);

	// Load mesh
	MeshData mesh = createPrimitiveCube();
	list_init(&_assets->meshes);
	list_add(&_assets->meshes, &mesh);

	// Load material
	MaterialData material;
	material.Name = "DefaultMaterial";
	material.DiffuseTextureID = TextureID;
	material.ShaderProgramID = programID;
	material.AssetID = 0;
	list_init(&_assets->materials);
	list_add(&_assets->materials, &material);
}

// TODO: Load assets into the library from XML manifest
void loadAssetLibraryManifest(AssetLibrary *_assets, char *_filename)
{
	printf("TODO: Implement loadAssetLibraryManifest()\n");
}