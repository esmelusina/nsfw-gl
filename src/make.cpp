
#include "glinc.h"
#include "nsfw\RenderObjects.h"
#include "nsfw\Vertex.h"

Geometry makeGeometry(const Vertex * verts, size_t nverts, const unsigned * idxes, size_t nidx)
{
	Geometry ret = { 0,0,0,0 };

	glGenBuffers(1, &ret.vbo);
	glGenBuffers(1, &ret.ibo);
	glGenVertexArrays(1, &ret.handle);
	ret.size = nidx;

	glBindVertexArray(ret.handle);
	glBindBuffer(GL_ARRAY_BUFFER, ret.vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ret.ibo);

	glBufferData(GL_ARRAY_BUFFER, nverts * sizeof(Vertex), verts, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nidx * sizeof(unsigned), idxes, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0); 

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);


	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	return ret;
}


bool freeGeometry(Geometry &g)
{
	glDeleteVertexArrays(1, &g.handle);
	glDeleteBuffers(1, &g.ibo);
	glDeleteBuffers(1, &g.vbo);
	g = { 0,0,0,0 };
	return true;
}


Shader makeShader(const char *vsource, const char *fsource, unsigned long long flags)
{
	Shader ret = { 0,flags };

	ret.handle = glCreateProgram();

	unsigned vs = glCreateShader(GL_VERTEX_SHADER);
	unsigned fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vs, 1, &vsource, 0);
	glShaderSource(fs, 1, &fsource, 0);

	glCompileShader(vs);
	glCompileShader(fs);

	glAttachShader(ret.handle, vs);
	glAttachShader(ret.handle, fs);

	glLinkProgram(ret.handle);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return ret;
}


bool freeShader(Shader &s)
{
	glDeleteProgram(s.handle);
	s = { 0,0 };
	return true;
}


