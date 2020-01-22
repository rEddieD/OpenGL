#pragma once
#include <common.hpp>
#include <glm.hpp>
#include "GL\glew.h"
#include <vector>

#define ONE_FOURSIDED_POLYGON_NUMBER_OF_VERTICES 6

class Terrain
{
public:
	Terrain();
	Terrain(const int WIDTH);
	~Terrain();
	unsigned int VertexNumber() const;
	unsigned int GetNIndeces() const;
	unsigned int VAO = 0;
	unsigned int VBO = 0;
	void LoadMesh();
private:
	unsigned int WiDTH = 8;
	std::vector<glm::vec3> vertices;
	unsigned int nIndices;
	void GenerateTerrain();
	std::vector<glm::vec3> vertexPositions;
};

