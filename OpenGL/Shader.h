#pragma once
#include <GL/glew.h>
#include <gl/GL.h>
#include <glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();

	void Use();

	int GetID() const;

private:
	unsigned int vertex = 0, fragment = 0;
	unsigned int ID = 0;
};
