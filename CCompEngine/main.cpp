#include "engine.h"

int main(int argc, char **argv)
{
	GameData data;

	initEngine(data, argc, argv);

	beginUpdate();

	return 0;
}