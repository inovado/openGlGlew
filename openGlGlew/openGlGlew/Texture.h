#pragma once

#include<cstring>
#include <GL/glew.h>

#include "CommonValue.h"

class Texture
{
public:
	Texture();
	Texture(const char* fileLoc);
	~Texture();

	bool LoadTexture();
	bool LoadTextureA();
	void UseTexture();
	void ClearTexture();

private:
	GLuint textureId;
	int width, height, bitDepth;
	const char* fileLocation;
};

//#pragma once
//
//#include <GL\glew.h>
//#include "stb_image.h"
//
//
//class Texture
//{
//public:
//	Texture();
//	Texture(const char* fileLoc);
//
//	void LoadTexture();
//	void ClearTexture();
//	void UseTexture();
//	
//
//
//	~Texture();
//
//private:
//	GLuint textureID;
//	int width, height, bitDepth;
//
//	const char* fileLocation;
//
//
//};

