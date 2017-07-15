#include "nsfw\Context.h"
#include "glinc.h"
#include <cstring>



bool Context::initialize(int a_width, int a_height, const char * a_title)
{
	glfwInit();

	width = a_width;
	height = a_height;
	strcpy_s(title, a_title);

	handle = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(handle);

	glewExperimental = true;
	glewInit();

	return true;
}

bool Context::terminate()
{
	glfwTerminate();
	return true;
}

bool Context::step()
{
	glfwPollEvents();
	glfwSwapBuffers(handle);
	return !glfwWindowShouldClose(handle);
}


double Context::getTime() const { return glfwGetTime(); }

bool Context::getKey(int key) const { return glfwGetKey(handle, key); }

bool Context::getMouseButton(int button) const { return glfwGetMouseButton(handle, button); }

void Context::getDim(int &w, int &h) const { w = width; h = height; }

void Context::getMousePos(double &x, double &y)  const { glfwGetCursorPos(handle, &x, &y); }
