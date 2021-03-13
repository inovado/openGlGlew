#pragma once

#include <GL/glew.h>

#include <string>
#include <vector>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "CommonValue.h"

#include "Mesh.h"
#include "Shader.h"


class Skybox
{
public:
	Skybox();

	Skybox(std::vector<std::string>faceLocation);

	void DrawSkybox(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

	~Skybox();

private:
	Mesh* skyMesh;
	Shader* skyShader;

	GLuint textureId;
	GLuint uniformProjection, uniformView;



};

