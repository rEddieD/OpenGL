#include "Terrain.h"

Terrain::Terrain()
{
	nIndices = (WiDTH-1) * (WiDTH-1) * ONE_FOURSIDED_POLYGON_NUMBER_OF_VERTICES;
	GenerateTerrain();
}

Terrain::Terrain(int width)
{
	nIndices = (width-1) * (width-1) * ONE_FOURSIDED_POLYGON_NUMBER_OF_VERTICES;
	WiDTH = width;
	GenerateTerrain();
}

Terrain::~Terrain()
{
	vertices.clear();
	vertexPositions.clear();
}

void Terrain::LoadMesh()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
}

void Terrain::GenerateTerrain()
{
	for (unsigned int z = 0; z < WiDTH; z++)
	{
		for (unsigned int x = 0; x < WiDTH; x++)
		{
			glm::vec3 v;
			v.x = (float(x) / 10.0f);
			v.y = ((float)(rand() % 100)) / 1000.0f;
			v.z = (float(z) / 10.0f);
			vertexPositions.push_back(v);
		}
	}

	std::vector<int> indices(nIndices, 0);
	unsigned int long long n = 0;
	while (n < nIndices)
	{
		//For row of faces
		for (unsigned int z = 0; z < WiDTH-1; ++z)
		{
			//For a face
			for (unsigned int x = 0; x < WiDTH-1; ++x)
			{
				indices[n] = x + z * WiDTH;
				indices[n + 1] = (x + 1) + z * WiDTH;
				indices[n + 2] = x + (z + 1) * WiDTH;
				indices[n + 3] = indices[n + 1];
				indices[n + 4] = indices[n + 2];
				indices[n + 5] = x + 1 + (z + 1) * WiDTH;
				n += 6;
			}
		}
	}

	for (unsigned int i = 0; i < nIndices; i++)
	{
		glm::vec3 vertex = vertexPositions.at(indices[i]);
		vertices.push_back(vertex);
	}
}

unsigned int Terrain::VertexNumber() const
{
	return vertices.size();
}

unsigned int Terrain::GetNIndeces() const
{
	return nIndices;
}
