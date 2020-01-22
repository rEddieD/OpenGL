#pragma once
#include "GL\glew.h"
#include "common.hpp"
#include <glm.hpp>

#include <Windows.h>

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>


class Mesh
{
public:
	Mesh();
	Mesh(char* filePath);
	void LoadMesh();
	//void LoadTerrain();
	void LoadVertices(char* filePath);
	bool IsLoaded();
	void Clean();
	unsigned int VertexNumber();
	unsigned int VAO = 0;
	unsigned int VBO = 0;

	
	std::vector<glm::vec3> vertexPositions;
	std::vector<unsigned int> vertexIndices;
	std::vector<glm::vec3> vertices;
	glm::vec3** vertexData = nullptr;
private:
	bool loaded = false;
};

