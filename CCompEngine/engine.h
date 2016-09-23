#ifndef ENGINE_H
#define ENGINE_H

// OpenGL Libraries
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

// Game data libraries
#include "asset_library.h"
#include "component_map.h"
#include "scene.h"

typedef struct GameData
{
	AssetLibrary assets;
	ComponentMap components;
	SceneMap scene;
} GameData;

// Engine data structures
typedef struct DisplaySettings
{
	unsigned int windowWidth;
	unsigned int windowHeight;
	unsigned int displayMode;
	unsigned int features;
} DisplaySettings;

// Core functions
void initEngine(GameData &_data, int argc, char **argv);
void beginUpdate();
void renderScene();
void updateScene();

// Engine I/O
DisplaySettings loadOrCreateDisplaySettings(char *_filename);

#endif