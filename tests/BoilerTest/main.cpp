
#include "nsfw\nsfw.h"

#include <iostream>

void main()
{
	Context context;

	Vertex shape[3] =
	{
		{ { -.5,-.5,0,1 }},
		{ { .5,-.5,0,1 } },
		{ { 0,.5,0,1 } }
	};

	unsigned idxs[3] = { 0,1,2 };

	// shader
	const char vert[] =
		"#version 430\n"
		"layout(location = 0) in vec4 position;\n"
		"void main() { gl_Position = position; }\n";

	const char frag[] =
		"#version 430\n"
		"out vec4 outColor;\n"
		"void main() { outColor = vec4(1.0,1.0,1.0,1.0); }\n";


	context.initialize(800, 600, "NSFW Context Test");

	Geometry g = makeGeometry(shape, 3, idxs, 3);
	Shader s = makeShader(vert, frag, 0);
	Framebuffer screen = { 0, 800,600 };

	while (context.step())
	{
		double x, y;
		int w, h;
		context.getMousePos(x, y);
		context.getDim(w, h);

		std::cout << x << ' ' << y << ' ' << w << ' ' << h << ' '
			<< context.getTime() << ' ' << context.getKey(' ') 
			<< ' ' << context.getMouseButton(0) << std::endl;

		clear(screen);
		draw(screen, s, g);
	}

	context.terminate();
}