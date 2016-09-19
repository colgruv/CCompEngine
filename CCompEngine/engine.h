#ifndef ENGINE_H
#define ENGINE_H

// OpenGL Libraries
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

// Developer Libraries
#include "shader.h"

// Engine data structures
typedef struct DisplaySettings
{
	unsigned int windowWidth;
	unsigned int windowHeight;
	unsigned int displayMode;
	unsigned int features;
} DisplaySettings;

// Core functions
void initEngine(int argc, char **argv);
void beginUpdate();
void renderScene();
void updateScene();

// Engine I/O
DisplaySettings loadOrCreateDisplaySettings(char *_filename);

#endif