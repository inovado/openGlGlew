#include "PointLight.h"



PointLight::PointLight()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	coefficient = linear = 0.0f;
	constant = 1.0f;
}

PointLight::PointLight(GLfloat red, GLfloat green, GLfloat blue,
	GLfloat intensity, GLfloat dIntensity,
	GLfloat xPos, GLfloat yPos, GLfloat zPos,
	GLfloat con, GLfloat lin, GLfloat coef) :Light(red, green, blue, intensity, dIntensity)
{
	position = glm::vec3(xPos, yPos, zPos);
	coefficient = coef;
	linear = lin;
	constant = con;
}

void PointLight::UseLight(GLuint ambientIntensityLoc, GLuint ambientColorLoc, GLuint diffuseIntensityLoc,
	GLuint positionLoc, GLuint constantLoc, GLuint linearLoc, GLuint coeffientLoc)
{
	Light::UseLight(ambientIntensityLoc, ambientColorLoc, diffuseIntensityLoc);
	glUniform3f(positionLoc, position.x, position.y, position.z);
	glUniform1f(coeffientLoc, coefficient);
	glUniform1f(linearLoc, linear);
	glUniform1f(constantLoc, constant);
}


PointLight::~PointLight()
{
}



//#include "PointLight.h"
//
//PointLight::PointLight() : Light()
//{
//	position = glm::vec3(0.0f, 0.0f, 0.0f);
//	constant = 1.0f;
//	linear = 0.0f;
//	exponent = 0.0f;
//}
//
//PointLight::PointLight(GLfloat red, GLfloat green, GLfloat blue,
//						GLfloat aIntensity, GLfloat dIntensity,
//						GLfloat xPos, GLfloat yPos, GLfloat zPos,
//						GLfloat con, GLfloat lin, GLfloat exp) : Light(red, green, blue, aIntensity, dIntensity)
//{
//	position = glm::vec3(xPos, yPos, zPos);
//	constant = con;
//	linear = lin;
//	exponent = exp;
//}
//
//void PointLight::UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, 
//							GLfloat diffuseIntensityLocation, GLfloat positionLocation, 
//							GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation)
//{
//
//	glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
//	glUniform1f(ambientIntensityLocation, ambientIntensity);
//	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
//
//	glUniform3f(positionLocation, position.x, position.y, position.z);
//	glUniform1f(constantLocation, constant);
//	glUniform1f(linearLocation, linear);
//	glUniform1f(exponentLocation, exponent);
//
//
//}
//
//PointLight::~PointLight()
//{
//}
