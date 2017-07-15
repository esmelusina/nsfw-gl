
#include "nsfw\context.h"
#include <iostream>

void main()
{
	Context context;

	context.initialize(800,600,"NSFW Context Test");

	while (context.step())
	{
		double x, y;
		int w, h;
		context.getMousePos(x, y);
		context.getDim(w, h);

		std::cout << x << ' ' << y << ' ' << w << ' ' << h << ' '
			<< context.getTime() << ' ' << context.getKey(' ') 
			<< ' ' << context.getMouseButton(0) << std::endl;

	}


	context.terminate();

}