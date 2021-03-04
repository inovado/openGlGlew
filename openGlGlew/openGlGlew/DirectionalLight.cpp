#pragma once

#include "DirectionalLight.h"



DirectionalLight::DirectionalLight() : Light()
{
	direction = glm::vec3(0.0f, -1.0f, 1.0f);
}

DirectionalLight::DirectionalLight(GLfloat red, GLfloat green, GLfloat blue,
	GLfloat intensity, GLfloat dIntensity,
	GLfloat xdir, GLfloat ydir, GLfloat zdir) : Light(red, green, blue, intensity, dIntensity)
{
	direction = glm::vec3(xdir, ydir, zdir);
}

void DirectionalLight::UseLight(GLuint ambientIntensityLoc, GLuint ambientColorLoc,
	GLuint diffuseIntensityLoc, GLuint directionLoc)
{
	Light::UseLight(ambientIntensityLoc, ambientColorLoc, diffuseIntensityLoc);
	glUniform3f(directionLoc, direction.x, direction.y, direction.z);
}

Light::~Light()
{
}

DirectionalLight::~DirectionalLight()
{
}



//#include "DirectionalLight.h"
//
//
//DirectionalLight::DirectionalLight() : Light()
//{
//
//	direction = glm::vec3(0.0f, -1.0f, 0.0f);
//}
//
//DirectionalLight::DirectionalLight(GLfloat red, GLfloat green, GLfloat blue,
//									GLfloat aIntensity, GLfloat dIntensity,
//									GLfloat xDir, GLfloat yDir, GLfloat zDir) : Light(red, green, blue, aIntensity, dIntensity)
//{
//	direction = glm::vec3(xDir, yDir, zDir);
//}
//
//void DirectionalLight::UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, 
//	GLfloat diffuseIntensityLocation, GLfloat directionLocation)
//{
// 	glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
//	glUniform1f(ambientIntensityLocation, ambientIntensity);
//
//	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
//	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
//}
//
//DirectionalLight::~DirectionalLight()
//{
//}
