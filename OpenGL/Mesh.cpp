#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(char* filePath)
{
	LoadVertices(filePath);

}


void Mesh::LoadMesh()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
}


void Mesh::LoadVertices(char* filePath)
{
	FILE *stream;
	errno_t err;
	err = fopen_s(&stream, filePath, "r");
	if (err != 0)
	{
		return;
	}

	while (true)
	{
		char line[128];
		int word = fscanf_s(stream, "%s", line, 128);
		if (word == EOF)
			break;
		if (strcmp(line, "v") == 0)
		{
			glm::vec3 vertex;
			fscanf_s(stream, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z, 128);
			vertexPositions.push_back(vertex);
		}
		else if (strcmp(line, "f") == 0)
		{
			unsigned int vertexIndex[3];
			fscanf_s(stream, "%d/%*d/%*d %d/%*d/%*d %d/%*d/%*d\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2], 128);
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
		}
	}


	/*std::ifstream modelFile;
	std::string line;
	std::size_t pos;
	modelFile.open(filePath, std::ios::in);
	if (modelFile.is_open())
	{
		while (!modelFile.eof())
		{
			std::getline(modelFile, line);
			if (line[0] == 'v')
			{
				float x, y, z;
				std::string s;
				std::istringstream iss(line);
				glm::vec3 vertex;
				iss >> s >> vertex.x >> vertex.y >> vertex.z;
				vertexPositions.push_back(vertex);
			}
			if (line[0] == 'f')
			{
				line = line.substr(2, line.size()-2);
				std::replace(line.begin(), line.end(), '/', ' ');
				std::istringstream iss(line);
				std::vector<int> numbers;
				for (int vertexIndex = 0; iss >> vertexIndex; ) {
					vertexIndices.push_back(vertexIndex);
				}
			}
		}
		loaded = true;
		modelFile.close();
	}
	else
	{
		MessageBox(0, "Cannot open the file specified", "Error", MB_OK);
	}*/

	for (unsigned int i = 0; i < vertexIndices.size(); i++)
	{
		glm::vec3 vertex = vertexPositions.at(vertexIndices.at(i)-1);
		vertices.push_back(vertex);
	}
}

bool Mesh::IsLoaded()
{
	return loaded;
}

void Mesh::Clean()
{
	vertexIndices.clear();
	vertexPositions.clear();
	vertices.clear();
}

unsigned int Mesh::VertexNumber()
{
	return vertices.size();
}
