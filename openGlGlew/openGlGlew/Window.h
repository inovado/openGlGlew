#pragma once

#include "stdio.h"
#include <cmath>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Window
{
public:
	Window();

	Window(GLint windowWidth, GLint windowHeight);

	int Initialise();

	GLint getBufferWidth() { return bufferWidth; }
	GLint getBufferHeight() { return bufferHeight; }

	bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }

	bool* getsKeys() { return keys; }
	const unsigned char* getButtons();
	const float* getAxes();
	GLfloat getXChange();
	GLfloat getYChange();

	void pollJoystickAxes();

	void swapBuffers() { glfwSwapBuffers(mainWindow); }

	~Window();

private:
	GLFWwindow* mainWindow;

	GLint width, height;
	GLint bufferWidth, bufferHeight;

	bool keys[1024];
	const float* axes;

	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	bool mouseFirstMoved;
	bool joystickFirstMoved;

	void createCallbacks();
	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
	static void handleJoystickConnected(int joy, int event);
};



//#pragma once
//
//#include "stdio.h"
//
//#include <GL\glew.h>
//#include <GLFW\glfw3.h>
//
//class Window
//{
//public:
//	Window();
//
//	Window(GLint windowWidth, GLint windowHeight);
//
//	int Initialise();
//
//	GLint getBufferWidth() { return bufferWidth; }
//	GLint getBufferHeight() { return bufferHeight; }
//
//	bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }
//
//	bool* getKeys() { return keys; }
//
//	GLfloat getXChange();
//	GLfloat getYChange();
//
//	void swapBuffers() { glfwSwapBuffers(mainWindow); }
//
//	~Window();
//
//private:
//	GLFWwindow* mainWindow;
//
//	GLint width, height;
//	GLint bufferWidth, bufferHeight;
//
//	bool keys[1024]; // cubre el rango de caracteres ascii
//
//	GLfloat lastX;
//	GLfloat lastY;
//	GLfloat xChange;
//	GLfloat yChange;
//	bool mouseFirstMoved;
//
//	void createCallbacks();
//	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode); // Used for callback functionality
//	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
//};
//
