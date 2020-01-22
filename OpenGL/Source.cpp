#include <fstream>
#include <cmath>
#include "Shader.h"
#include "RenderEngine.h"
#include "Mesh.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Terrain.h"


int main()
{
	Window w;
	w.createDisplay();

	Mesh Tire("Tire.obj");
	Tire.LoadMesh();

	unsigned int tireverts = Tire.VertexNumber();

	Tire.Clean();

	Terrain T(64);

	T.LoadMesh();

	unsigned int terrainverts = T.GetNIndeces();

	Shader ourShader("shader.vs", "shader.fs");


	if(w.window != NULL)
	while (!glfwWindowShouldClose(w.window))
	{
		w.processInput();

		glClearColor(0.2f, 0.2f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ourShader.Use();
		
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -1.0f, -5.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)w.GetWidth() / (float)w.GetHeight(), 0.1f, 100.0f);


		unsigned int modelLoc = glGetUniformLocation(ourShader.GetID(), "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		unsigned int viewLoc = glGetUniformLocation(ourShader.GetID(), "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		
		unsigned int projectionLoc = glGetUniformLocation(ourShader.GetID(), "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));


		glBindVertexArray(Tire.VAO);
		glDrawArrays(GL_TRIANGLES, 0, tireverts);


		glBindVertexArray(T.VAO);
		glDrawArrays(GL_TRIANGLES, 0, terrainverts);
		
		w.updateDisplay();
	}

	glDeleteVertexArrays(1, &Tire.VAO);
	glDeleteBuffers(1, &Tire.VBO);

	glDeleteVertexArrays(1, &T.VAO);
	glDeleteBuffers(1, &T.VBO);

	glfwTerminate();
	return 0;
}