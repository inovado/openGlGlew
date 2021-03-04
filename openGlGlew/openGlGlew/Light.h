
#pragma once

#include<GL/glew.h>
#include<glm/glm.hpp>

class Light
{
public:
	Light();
	Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity, GLfloat dIntensity);


	virtual ~Light() = 0;

protected:
	glm::vec3 color;
	GLfloat ambientIntensity;
	GLfloat diffuseIntensity;

	virtual void UseLight(GLuint ambientIntensityLoc, GLuint ambientColorLoc, GLuint diffuseIntensityLoc);
};

//#pragma once
//
//#include <glm\glm.hpp>
//#include <GL/glew.h>
//
//class Light
//{
//public:
//	Light();
//	
//	Light(GLfloat red, GLfloat green, GLfloat blue, 
//		GLfloat aIntensity, GLfloat dIntensity);
//
// 	//void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, GLfloat diffuseIntensityLocation);
//
//	~Light();
//
//
//protected:
//	glm::vec3 colour;
//	GLfloat ambientIntensity;
//	GLfloat diffuseIntensity;
//	
//
//
//};

