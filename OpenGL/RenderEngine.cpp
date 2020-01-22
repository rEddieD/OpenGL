#include "RenderEngine.h"

void Window::createDisplay()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDTH, HEIGHT, WINDOWTITLE, NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSetWindowSizeLimits(window, MINWIDTH, MINHEIGHT, GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glewInit();
}


void Window::updateDisplay()
{
	glfwSwapInterval(1);
	glfwSwapBuffers(window);
	glfwPollEvents();
	glfwGetFramebufferSize(window, &WIDTH, &HEIGHT);
}


void Window::closeDisplay()
{
	glfwTerminate();
}


void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::processInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int Window::GetWidth() const
{
	return WIDTH;
}

int Window::GetHeight() const
{
	return HEIGHT;
}

void Window::SetWidth(int width)
{
	WIDTH = width;
}

void Window::SetHeight(int height)
{
	HEIGHT = height;
}
