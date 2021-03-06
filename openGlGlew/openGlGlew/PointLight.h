#pragma once
#include "Light.h"

class PointLight :
	public Light
{
public:
	PointLight();
	PointLight(GLfloat red, GLfloat green, GLfloat blue,
		GLfloat intensity, GLfloat dIntensity,
		GLfloat xPos, GLfloat yPos, GLfloat zPos,
		GLfloat con, GLfloat lin, GLfloat exp);

	virtual void UseLight(GLuint ambientIntensityLoc, GLuint ambientColorLoc, GLuint diffuseIntensityLoc,
		GLuint positionLoc, GLuint constantLoc, GLuint linearLoc, GLuint coeffientLoc);

	~PointLight();

protected:
	glm::vec3 position;
	GLfloat constant, linear, coefficient;
};



//#pragma once
//#include "Light.h"
//class PointLight :
//    public Light
//{
//public:
//    PointLight();
//
//    PointLight(GLfloat red, GLfloat green, GLfloat blue,
//        GLfloat aIntensity, GLfloat dIntensity,
//        GLfloat xPos, GLfloat yPos, GLfloat zPos,
//        GLfloat con, GLfloat lin, GLfloat exp);
//
//    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
//        GLfloat diffuseIntensityLocation, GLfloat positionLocation,
//        GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation);
//
//
//    ~PointLight();
//
//
//private:
//    glm::vec3 position;
//
//    GLfloat constant, linear, exponent;
//};
//
