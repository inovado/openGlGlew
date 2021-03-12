#include "Texture.h"

Texture::Texture()
{
	textureId = 0;
	width = 0;
	height = 0;
	bitDepth = 0;
	fileLocation = "";
}

Texture::Texture(const char* fileLoc)
{
	textureId = 0;
	width = 0;
	height = 0;
	bitDepth = 0;
	fileLocation = fileLoc;
}


Texture::~Texture()
{
	ClearTexture();
}



bool Texture::LoadTexture()
{
	unsigned char* data = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
	if (!data)
	{
		printf("Failed to find: %s\n", fileLocation);
		return false;
	}

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);

	return true;
}



bool Texture::LoadTextureA()
{
	unsigned char* data = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
	if (!data)
	{
		printf("Failed to find: %s\n", fileLocation);
		return false;
	}

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);

	return true;
}
void Texture::UseTexture()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::ClearTexture()
{
	glDeleteTextures(1, &textureId);
	textureId = 0;
	width = 0;
	height = 0;
	bitDepth = 0;
	fileLocation = "";
}




//#include "Texture.h"
//
//Texture::Texture()
//{
//	textureID = 0;
//	width = 0;
//	height = 0;
//	bitDepth = 0;
//	fileLocation = "";
//}
//
//Texture::Texture(const char* fileLoc)
//{
//	textureID = 0;
//	width = 0;
//	height = 0;
//	bitDepth = 0;
//	fileLocation = fileLoc;
//}
//
//
//
//void Texture::LoadTexture()
//{
//	unsigned char* texData = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
//
//	if (!texData)
//	{
//		printf("Failed to find: %s\n", fileLocation);
//		return;
//	}
//
//	glGenTextures(1, &textureID);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//
//	//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // REpetecion de textura sobre objeto
//	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); // REpetecion de textura sobre objeto EN REFLEJO
//	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // REpetecion de textura sobre objeto EN REFLEJO
//	
//
//	//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // REpetecion de textura sobre objeto
//	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT); // REpetecion de textura sobre objeto EN REFLEJO
//	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // REpetecion de textura sobre objeto EN REFLEJO
//	
//	
//	//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //FILTRO
//	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //FILTRO
//	//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //FILTRO
//	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //FILTRO
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
//	glGenerateMipmap(GL_TEXTURE_2D);
//
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	stbi_image_free(texData);
//	
//
//
//}
//
//void Texture::ClearTexture()
//{
//	glDeleteTextures(1, &textureID);
//	textureID = 0;
//	width = 0;
//	height = 0;
//	bitDepth = 0;
//	fileLocation = "";
//}
//
//void Texture::UseTexture()
//{
//	glActiveTexture(GL_TEXTURE);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//}
//
//
//
//Texture::~Texture()
//{
//	ClearTexture();
//}
