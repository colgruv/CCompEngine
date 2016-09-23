#include "engine.h"
#include <iostream>

// Initialize OpenGL context
void initEngine(GameData &_data, int argc, char **argv)
{
	glutInit(&argc, argv);
	
	DisplaySettings settings = loadOrCreateDisplaySettings("display.txt");

	// Default display parameters
	glutInitDisplayMode(settings.displayMode);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(settings.windowWidth, settings.windowHeight);
	
	// Create window
	glutCreateWindow("CComp - Debug");

	// Initialize GLEW
	glewInit();
	if (glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << " GLEW Version is 4.5\n ";
	}
	else
	{
		std::cout << "GLEW 4.5 not supported\n ";
	}

	// Enable renderer features
	glEnable(settings.features);

	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Initialize asset library
	initAssetLibrary(&_data.assets);

	// Create and compile our GLSL program from the shaders
	//GLuint programID = LoadShaders("TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader");

	// Get a handle for our "MVP" uniform
	ShaderData *defaultShader = LIST_GET(_data.assets.shaders, ShaderData*, 0);
	GLuint MatrixID = glGetUniformLocation(defaultShader->ShaderProgramID, "MVP");

	// Register callbacks
	glutDisplayFunc(renderScene);
}

// OpenGL Rendering callback
void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f, 0.7f, 1.0f, 1.0f);


	//glUniformMatrix4fv()
	glutSwapBuffers();
}

// TODO: OpenGL Game Logic callback
void updateScene()
{

}

// Begin OpenGLs Main Loop function, while issues callbacks for the Engine to handle when appropriate
void beginUpdate()
{
	glutMainLoop();
}

// Load engine display settings from a file, or set defaults and create a file
// TODO: Change format to binary
DisplaySettings loadOrCreateDisplaySettings(char *_filename)
{
	DisplaySettings settings;

	// Check for settings file
	FILE *settingsFile;
	fopen_s(&settingsFile, _filename, "r");
	if (fgetc(settingsFile) == EOF)
	{
		// reopen file for writing
		fclose(settingsFile);
		fopen_s(&settingsFile, _filename, "w");

		// If no file, set to defaults
		printf("No engine settings file found; setting defaults...\n");
		settings.windowWidth = 800;
		settings.windowHeight = 600;
		settings.displayMode = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
		settings.features = GL_DEPTH_TEST;

		// Write file
		char number[8];
		printf("Writing engine settings file...\n");
		_itoa_s(settings.windowWidth, number, 4, 10);
		fprintf(settingsFile, ".WWDTH:%s\n", number);
		_itoa_s(settings.windowHeight, number, 4, 10);
		fprintf(settingsFile, "WHGHT:%s\n", number);
		_itoa_s(settings.displayMode, number, 8, 10);
		fprintf(settingsFile, "DMODE:%s\n", number);
		_itoa_s(settings.features, number, 8, 10);
		fprintf(settingsFile, "FEATS:%s\n.", number);
		fclose(settingsFile);
	}
	else
	{
		printf("Settings file found. Reading settings...\n");
		char line[255];
		char setting[6];
		char value[32];
		do
		{
			// Read a line from the file
			fgets(line, 255, (FILE*)settingsFile);
			
			// Item setting
			strncpy_s(setting, sizeof(char)*6, line, 5);

			// Item value
			strcpy_s(value, sizeof(char)*32, line + 6);

			if (strstr(setting, "WWDTH"))
			{
				settings.windowWidth = atoi(value);
			}
			else if (strstr(setting, "WHGHT"))
			{
				settings.windowHeight = atoi(value);
			}
			else if (strstr(setting, "DMODE"))
			{
				settings.displayMode = atoi(value);
			}
			else if (strstr(setting, "FEATS"))
			{
				settings.features = atoi(value);
			}
		} while (line[0] != '.');

		// Deallocate buffers
		//(line);
		//free(setting);
		//free(value);
	}

	return settings;
}