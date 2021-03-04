#include "Light.h"

Light::Light()
{
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;
	diffuseIntensity = 0.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity, GLfloat dIntensity)
{
	color = glm::vec3(red, green, blue);
	ambientIntensity = intensity;
	diffuseIntensity = dIntensity;
}

void Light::UseLight(GLuint ambientIntensityLoc, GLuint ambientColorLoc, GLuint diffuseIntensityLoc)
{
	glUniform3f(ambientColorLoc, color.x, color.y, color.z);
	glUniform1f(ambientIntensityLoc, ambientIntensity);
	glUniform1f(diffuseIntensityLoc, diffuseIntensity);
}


//Light::~Light()
//{
//}


//#include "Light.h"
//
//Light::Light()
//{
//	colour = glm::vec3(1.0f, 1.0f, 1.0f);
//	ambientIntensity = 1.0f;
//	diffuseIntensity = 0.0f;
//}
//
//Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity)
//{
//	colour = glm::vec3(red, green, blue);
//	ambientIntensity = aIntensity;
//	diffuseIntensity = dIntensity;
//}
//
////void Light::UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, GLfloat diffuseIntensityLocation)
////{
////	glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
////	glUniform1f(ambientIntensityLocation, ambientIntensity);
////
////	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
////	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
////}
//
//Light::~Light()
//{
//}
