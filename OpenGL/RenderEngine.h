#pragma once
#include "GL\glew.h"
#include "glfw3.h"


class Window
{
public:
	GLFWwindow* window = nullptr;

	void createDisplay();
	void updateDisplay();
	void closeDisplay();
	void static framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput();
	int GetWidth() const;
	int GetHeight() const;
	void SetWidth(int width);
	void SetHeight(int height);
private:
	int WIDTH = 1280;
	int HEIGHT = 720;
	int MINWIDTH = 1024;
	int MINHEIGHT = 720;
	const char* WINDOWTITLE = "Game of Something";
};


