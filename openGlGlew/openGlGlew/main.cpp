
//---------copia extraida de https://github.com/mpro34/OpenGLCourseApp/tree/fcdb0e329d72bbf33c264ad279d9357a75d6d69b/OpenGLCourseApp

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

#include "Camera.h"


const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
Camera camera;

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;


// Vertex Shader
static const char* vShader = "Shaders/shader.vert";

// Fragment Shader
static const char* fShader = "Shaders/shader.frag";

void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		-1.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj2);

}


void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

int main()
{

	mainWindow = Window(800, 600);
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f); // matriz camera

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);

	// Loop until window closed
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime(); // SDL_GetPerfomanceCounter();  
		deltaTime = now - lastTime;  // (now - lastTime)*1000 / SDL_GetPerfomanceFrequency();  
		lastTime = now;

		// Get + Handle user input events
		glfwPollEvents();

		camera.keyControl(mainWindow.getKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glUseProgram(shader);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();

		glm::mat4 model(1.0f);

		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		meshList[0]->RenderMesh();

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 1.0f, -2.5f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}


//----------------------------------- COPIA GIT HASTA -- 216 CODING CLEAN UP -- --------------------------------------
//#include <stdio.h>
//#include <string.h>
//#include <cmath>
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//const GLint WIDTH = 800, HEIGHT = 600;
//const float toRadians = 3.14159265f / 180.0f;
//
//GLuint VAO, VBO, shader, uniformModel;
//
//bool direction = true;
//float triOffset = 0.0f;
//float triMaxoffset = 0.7f;
//float triIncrement = 0.0005f;
//
//float curAngle = 0.0f;
//
//// Vertex Shader - TODO: Update xMove to vec4 called model and multiply in main()
//static const char* vShader = "												\n\
//#version 330																\n\
//																			\n\
//layout (location = 0) in vec3 pos;											\n\
//																			\n\
//uniform mat4 model;											    			\n\
//																			\n\
//void main()																	\n\
//{																			\n\
//	gl_Position = model * vec4(0.4 * pos.x, 0.4 * pos.y, pos.z, 1.0);       \n\
//}";
//
//// Fragment Shader
//static const char* fShader = "										\n\
//#version 330														\n\
//																	\n\
//out vec4 color;														\n\
//																	\n\
//void main()															\n\
//{																	\n\
//	color = vec4(1.0, 0.0, 0.0, 1.0);       \n\
//}";
//
//void CreateTriangle()
//{
//	GLfloat vertices[] = {
//		-1.0f, -1.0f, 0.0f,
//		1.0f, -1.0f, 0.0f,
//		0.0f, 1.0f, 0.0f
//	};
//
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glBindVertexArray(0);
//
//}
//
//void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
//{
//	GLuint theShader = glCreateShader(shaderType);
//
//	const GLchar* theCode[1];
//	theCode[0] = shaderCode;
//
//	GLint codeLength[1];
//	codeLength[0] = strlen(shaderCode);
//
//	glShaderSource(theShader, 1, theCode, codeLength);
//	glCompileShader(theShader);
//
//	GLint result = 0;
//	GLchar eLog[2014] = { 0 };
//
//	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
//		printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
//		return;
//	}
//
//	glAttachShader(theProgram, theShader);
//}
//
//void CompileShaders()
//{
//	shader = glCreateProgram();
//
//	if (!shader)
//	{
//		printf("Error creating shader program\n");
//		return;
//	}
//
//	AddShader(shader, vShader, GL_VERTEX_SHADER);
//	AddShader(shader, fShader, GL_FRAGMENT_SHADER);
//
//	GLint result = 0;
//	GLchar eLog[2014] = { 0 };
//
//	glLinkProgram(shader);
//	glGetProgramiv(shader, GL_LINK_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		printf("Error linking program: '%s'\n", eLog);
//		return;
//	}
//
//	glValidateProgram(shader);
//	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		printf("Error validating program: '%s'\n", eLog);
//		return;
//	}
//
//	uniformModel = glGetUniformLocation(shader, "model");
//}
//
//int main()
//{
//	// Initialize GLFW
//	if (!glfwInit())
//	{
//		printf("GLFW Initialization failed!");
//		glfwTerminate();
//		return 1;
//	}
//
//	// Setup GLFW Window Properties
//	// OpenGL Version
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	// core proffile = No backwards compatibility
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	// Allow forward compatibility
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
//	if (!mainWindow)
//	{
//		printf("GLFW window creation failed!");
//		glfwTerminate();
//		return 1;
//	}
//
//	// Get Buffer size information
//	int bufferWidth, bufferHeight;
//	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
//
//	// Set context for GLEW to use
//	glfwMakeContextCurrent(mainWindow);
//
//	// Allow modern extension features
//	glewExperimental = GL_TRUE;
//
//	if (glewInit() != GLEW_OK)
//	{
//		printf("GLEW init failed!");
//		glfwDestroyWindow(mainWindow);
//		glfwTerminate();
//		return 1;
//	}
//
//	// Setup Viewport size
//	glViewport(0, 0, bufferWidth, bufferHeight);
//
//	CreateTriangle();
//	CompileShaders();
//
//	// Loop until window closed
//	while (!glfwWindowShouldClose(mainWindow))
//	{
//		// Get + Handle user input events
//		glfwPollEvents();
//
//		if (direction) {
//			triOffset += triIncrement;
//		}
//		else
//		{
//			triOffset -= triIncrement;
//		}
//
//		if (abs(triOffset) >= triMaxoffset)
//		{
//			direction = !direction;
//		}
//
//		curAngle += 0.01f;
//		if (curAngle >= 360)
//		{
//			curAngle -= 360;
//		}
//
//		// Clear window
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shader);
//
//		glm::mat4 model(1.0f);
//		model = glm::translate(model, glm::vec3(triOffset, 0.0f, 0.0f));
//		model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
//
//		//glUniform1f(uniformXMove, triOffset);
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//
//		glUseProgram(0);
//
//		glfwSwapBuffers(mainWindow);
//
//	}
//
//	return 0;
//}



//------------------------------------------ -205 CODING Shaders and the First Triangle--------------------------------------

//#include <stdio.h>
//#include <string.h>
//#include <cmath>
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <glm\glm.hpp>
//#include <glm\gtc\matrix_transform.hpp>
//#include <glm\gtc\type_ptr.hpp>
//
//const GLint width = 800, height = 600;
//const float toRadians = 3.14159265f / 180.0f;
//
//GLuint VAO, VBO, IBO, shader, uniformModel, uniformProjection; // VAO-matriz de vertices  VBO-bufer de vertices
//
//bool direction = true;
//float triOffset = 0.001f;
//float triMaxoffset = 0.7f;
//float triIncrement = 0.0005f; 
//
//float curAngle = 0.0f;
//
//bool sizeDirection = true;
//float curSize = 0.4f;
//float maxSize = 0.8f;
//float minSize = 0.1f;
//
//
//
//// Vertex Shader
//static const char* vShader = "											\n\
//#version 330															\n\
//																		\n\
//layout (location = 0) in vec3 pos;										\n\
//																		\n\
//out vec4 vCol;															\n\
//																		\n\
//uniform mat4 model;														\n\
//uniform mat4 projection;												\n\
//																		\n\
//void main()																\n\
//{																		\n\
////gl_Position = proyection * model * vec4(5.0 * pos.x, 5.0 * pos.y, pos.z, 0.5);	\n\
////gl_Position = vec4(0.4 * pos.x, 0.4* pos.y, pos.z, 1.0);				\n\
////gl_Position = model * vec4(pos, 1.0);								\n\
//gl_Position = vec4(pos, 1.0);											\n\
//vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);								\n\
//}";
//
//
//// fragment shader
//static const char* fShader = "									\n\
//#version 330													\n\
//																\n\
//in vec4 vCol;													\n\																																\n\
//out vec4 colour;												\n\
//																\n\
//void main()														\n\
//{																\n\
//	colour = vCol;												\n\
//}";
//
//
//
//
////crear trianulo
//void CreateTriangle()
//{
//	unsigned int indices[] = {
//		0, 3, 1,
//		1, 3, 2,
//		2, 3, 0,
//		0 ,1, 2 
//	};
//
//	GLfloat vertices[] = {
//		-1.0f, -1.0f, 0.0f,
//		 0.0f,-1.0f,1.0f,
//		 1.0f, -1.0f, 0.0f,
//		 0.0f,  1.0f, 0.0f
//	};
//
//	glGenVertexArrays(1, &VAO); //cantidad de matrices que se desea crear
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &IBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//
//	glBindVertexArray(0);
//}
//
//void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) // agrega shaders
//{
//	GLuint theShader = glCreateShader(shaderType);
//
//	const GLchar* theCode[1];
//	theCode[0] = shaderCode;
//
//	GLint codeLength[1];
//	codeLength[0] = strlen(shaderCode);
//
//	glShaderSource(theShader, 1, theCode, codeLength);
//	glCompileShader(theShader);
//
//	GLint result = 0;
//	GLchar eLog[1024] = { 0 };
//
//	//glGetProgramiv(theShader, GL_COMPILE_STATUS, &result);
//	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
//		printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
//		return;
//	}
//	glAttachShader(theProgram, theShader);
//}
//
//
//void CompileShaders() {
//	shader = glCreateProgram();
//
//	if (!shader)
//	{
//		printf("Error creating shader program! \n");
//		return;
//	}
//
//	AddShader(shader, vShader, GL_VERTEX_SHADER);
//	AddShader(shader, fShader, GL_FRAGMENT_SHADER);
//
//	GLint result = 0;
//	GLchar eLog[1024] = { 0 };
//
//	glLinkProgram(shader);
//	glGetProgramiv(shader, GL_LINK_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		printf("Error linking program: '%s'\n", eLog);
//		return;
//	}
//
//	glValidateProgram(shader);
//	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
//	if (!result)
//	{
//		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
//		printf("Error validating program: '%s'\n", eLog);
//		return;
//	}
//
//	uniformModel = glGetUniformLocation(shader, "model");
//	uniformProjection = glGetUniformLocation(shader, "projection");
//}
//
//
//int main()
//{
//	//inicializacion GLFW
//	if (!glfwInit())
//	{
//		printf("GLFW initialization failed");
//		glfwTerminate();
//		return 1;
//	}
//
//	// setup GLFW window properties
//	// openGL version
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	// Core profile = No backwards Compatibility
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	// Allow forward compatibility
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//	GLFWwindow* mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
//	if (!mainWindow)
//	{
//		printf("GLFW window creation failed");
//		glfwTerminate();
//		return 1;
//	}
//
//	// Get buffer size information
//	int bufferWidth, bufferHeight;
//	glfwGetFramebufferSize(mainWindow, &bufferHeight, &bufferWidth);
//
//	// Set context for GLEW to use
//	glfwMakeContextCurrent(mainWindow);
//
//	// Allow modern extension features
//	glewExperimental = GL_TRUE;
//
//	if (glewInit() != GLEW_OK)
//	{
//		printf("GLEW  initialization failed!");
//		glfwDestroyWindow(mainWindow);
//		glfwTerminate();
//		return 1;
//	}
//
//	glEnable(GL_DEPTH_TEST);
//
//	// Setup Viewport size
//	glViewport(0, 0, bufferWidth, bufferHeight);
//
//	CreateTriangle();
//	CompileShaders();
//
//	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)bufferWidth / (GLfloat)bufferHeight, 0.1f, 100.0f);
//
//	// Loop until window closed
//	while (!glfwWindowShouldClose(mainWindow))
//	{
//		// Get + Handle user input events
//		glfwPollEvents();
//
//		if (direction)
//		{
//			triOffset += triIncrement;
//		}
//		else
//		{
//			triOffset -= triIncrement;
//		}
//
//		if (abs(triOffset) >= triMaxoffset)
//		{
//			direction = !direction;
//		}
//
//		curAngle += 0.001f;
//		if (curAngle >= 360)
//		{
//			curAngle -= 360;
//		}
//
//		if (sizeDirection)
//		{
//			curSize += 0.0001f;
//		}
//		else
//		{
//			curSize -= 0.0001f;
//		}
//
//		if (curSize >= maxSize || curSize <= minSize)
//		{
//			sizeDirection = !sizeDirection;
//		}
//
//		// Clear window
//		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glUseProgram(shader);
//
//		glm::mat4 model;
//		
//		model = glm::translate(model, glm::vec3(0.01f, triOffset , -2.5f)); // sentido en el que se movera el shader, ejes x, y, z
//		//model = glm::scale(model, glm::vec3(curSize, curSize, 1.0f)); // primero debe ir la escala
//		//model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.01f, 0.01f, 0.01f));
//		
//		
//		//glUniform1f(uniformModel, triOffset); 
//		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
//
//		glBindVertexArray(VAO);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//		glBindVertexArray(0);
//
//		glUseProgram(0);
//
//		glfwSwapBuffers(mainWindow);
//	}
//
//
//
//	return 0;
//}