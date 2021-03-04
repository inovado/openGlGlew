#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>
#include "CommonValue.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

class Shader
{
public:
	Shader();

	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

	std::string ReadFile(const char* fileLocation);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetAmbientIntensityLocation();
	GLuint GetAmbientColorLocation();
	GLuint GetDiffuseIntensityLocation();
	GLuint GetDirectionLocation();
	GLuint GetSpecularIntensityLocation();
	GLuint GetShininessLocation();
	GLuint GetEyePositionLocation();

	void SetDirectionalLight(DirectionalLight* light);
	void SetPointLights(PointLight* light, unsigned int lightCount);
	void SetSpotLights(SpotLight* light, unsigned int lightCount);

	void UseShader();
	void ClearShader();

	~Shader();

private:
	unsigned int pointLightCount;
	unsigned int spotLightCount;
	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
		uniformSpecularIntensity, uniformShininess;

	GLuint uniformPointLightCount;
	GLuint uniformSpotLightCount;
	struct {
		GLuint color;
		GLuint ambientIntensity;
		GLuint diffuseIntensity;

		GLuint direction;
	}uniformDirectionalLight;

	struct {
		GLuint color;
		GLuint ambientIntensity;
		GLuint diffuseIntensity;

		GLuint position;
		GLuint coefficient;
		GLuint linear;
		GLuint constant;
	}uniformPointLight[MAX_POINT_LIGHTS];

	struct {
		GLuint color;
		GLuint ambientIntensity;
		GLuint diffuseIntensity;

		GLuint position;
		GLuint coefficient;
		GLuint linear;
		GLuint constant;

		GLuint direction;
		GLuint edge;
	}uniformSpotLight[MAX_SPOT_LIGHTS];

	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};



//#pragma once
//
//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <fstream>
//
//#include <GL\glew.h>
//
//#include "DirectionalLight.h"
//#include "PointLight.h"
//#include "CommonValue.h"
//
//
//class Shader
//{
//public:
//	Shader();
//
//	void CreateFromString(const char* vertexCode, const char* fragmentCode);
//	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);
//
//	std::string ReadFile(const char* fileLocation);
//
//	GLuint GetProjectionLocation();
//	GLuint GetModelLocation();
//	GLuint GetViewLocation();
//	GLuint GetAmbientIntensityLocation();
//	GLuint GetAmbientColourLocation();
//	GLuint GetDiffuseIntensityLocation();
//	GLuint GetDirectionLocation();
//	GLuint GetSpecularIntensityLocation();
//	GLuint GetShininessLocation();
//	GLuint GetEyePositionLocation();
//
//
//	void SetDirectionalLight(DirectionalLight *dLight);
//
//	void SetPointLights(PointLight* pLight, unsigned int lightCount);
//
//	void UseShader();
//	void ClearShader();
//
//	~Shader();
//
//private:
//	int pointLightCount;
//
//	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition, 
//					uniformSpecularIntensity, uniformShininess;
//
//	struct 
//	{
//		GLuint uniformColour;
//		GLuint uniformAmbientIntensity;
//		GLuint uniformDiffuseIntensity;
//		GLuint uniformDirection;
//
//	} uniformDirectionalLight;
//
//	GLuint uniformPointLightCount;
//
//	struct
//	{
//		GLuint uniformColour;
//		GLuint uniformAmbientIntensity;
//		GLuint uniformDiffuseIntensity;
//		GLuint uniformPosition;
//		GLuint uniformConstant;
//		GLuint uniformLinear;
//		GLuint uniformExponent;
//
//	}uniformPointLight[MAX_POINT_LIGHTS]; // 30 MINS
//
//	void CompileShader(const char* vertexCode, const char* fragmentCode);
//	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
//
//	
//};
//
