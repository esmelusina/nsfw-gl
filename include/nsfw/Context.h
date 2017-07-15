#pragma once


struct GLFWwindow;


class Context
{
	GLFWwindow *handle;
	int width, height;
	char title[64];

public:
	bool initialize(int width, int height, const char *title);
	bool terminate();
	bool step();

	double getTime() const;
	bool getKey(int k) const;
	bool getMouseButton(int b) const;
	void getDim(int &w, int &h) const;
	void getMousePos(double &x, double &y) const;

};