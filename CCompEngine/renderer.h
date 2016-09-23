#ifndef RENDERER_H
#define RENDERER_H

typedef struct RendererComponent
{
	unsigned int actorID;
	unsigned int meshID;
	unsigned int materialID;
} RendererComponent;

void drawRenderer(RendererComponent *_renderer);

#endif
