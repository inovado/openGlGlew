#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
public:
	DirectionalLight();
	~DirectionalLight();

	DirectionalLight(GLfloat red, GLfloat green, GLfloat blue,
		GLfloat intensity, GLfloat dIntensity,
		GLfloat xdir, GLfloat ydir, GLfloat zdir);

	virtual void UseLight(GLuint ambientIntensityLoc, GLuint ambientColorLoc,
		GLuint diffuseIntensityLoc, GLuint directionLoc);

private:
	glm::vec3 direction;
};

//#pragma once
//#include "Light.h"
//class DirectionalLight :
//    public Light
//{
//public: 
//    DirectionalLight();
//    DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, 
//                     GLfloat aIntensity, GLfloat dIntensity,
//                     GLfloat xDir, GLfloat yDir, GLfloat zDir);
//
//    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, 
//        GLfloat diffuseIntensityLocation, GLfloat directionLocation);
//
//
//    ~DirectionalLight();
//
//private:
//    glm::vec3 direction;
//
//};

