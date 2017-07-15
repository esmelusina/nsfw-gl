#pragma once

struct Geometry
{
	unsigned handle, vbo, ibo, size;
};


struct Shader
{
	unsigned handle;
	unsigned long long flags;
};

struct Framebuffer
{
	unsigned handle, width, height;
};