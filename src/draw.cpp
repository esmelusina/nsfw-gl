#include "glinc.h"
#include "nsfw\RenderObjects.h"


void draw(const Framebuffer &f, const Shader &s, const Geometry &g)
{

	glBindFramebuffer(GL_FRAMEBUFFER, f.handle);
	glUseProgram(s.handle);
	glBindVertexArray(g.handle);

	glViewport(0, 0, f.width, f.height);

	glDrawElements(GL_TRIANGLES, g.size, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void clear(const Framebuffer &f, float r, float g, float b, float a, bool doC, bool doB)
{
	glClearColor(r, g, b, a);
	glBindFramebuffer(GL_FRAMEBUFFER, f.handle);
	glClear((GL_DEPTH_BUFFER_BIT*doC) | (GL_COLOR_BUFFER_BIT*doB));
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}