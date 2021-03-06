/* Teoria

GLFW (creaci�n de contexto) + GLEW (carga de extensi�n) y tendr� una configuraci�n 
completamente completa para aplicaciones OpenGL multiplataforma que funcionan en 
Windows, Mac y Linux y son compatibles con todas las extensiones OpenGL modernas.

B�sicamente, GLFW crear� una ventana OpenGL para que pueda usar; sin embargo, 
no es responsable de cargar extensiones de OpenGL (funciones que le permiten 
hacer cosas modernas de OpenGL como usar sombreadores o FBO / VBO, etc. Por lo 
tanto, deber� llamar a la funci�n de inicio de GLEW para obtener acceso a ellas. 
Implementar GLEW en su c�digo no deber�a ser m�s que incluir el encabezado y 
llamar a GlewInit ();


The rendering pipiline Stages

1. Vertex Specification
2. Vertex Shader(programmable)
3. Tessellation (programmable)
4. Geometry shader (programmable)
5. Vertex Post-Processing
6. Primitive Assembly
7. Rasterization
8. Fragment shader(programmable)
9. Per-sample operations

-------------------------------------------204-Shaders and the rendering pipeline--------------------------------------

- Tessellation
- Geometry Shader

- Rasterization
	- Converts primitives in to "Fragments".
	- Fragments are pieces of data for each pixel, obtained from the rasterization process
	- Fragments data will be interpolated based on its position relative to each vertex.

* Creating a shader program

1.Create empty program
2.Create empty shaders
3.Attach shader source code to shaders
4.Compile shaders
5.Attach shders to program
6.Link program (creates executables from shaders and links them together)
4.Validate program (optional but highly advised because debbugging shaders is a pain).

Summary
- Rendering pipeline consist of several stages
- Four stages are programmable via shaders ( Vertex, Tessellation, Geometry, Fragment)
- Vertex shader is mandatory
- Vertices: user-defined points in space
- Primitives: Groups of vertices that make a simple shape ( usually a triangle).
- Fragments: Per-pixel data created from primitives
- Vertex Array Object(VAO): WHAT data a vertex has 
- Vertex Buffer Object(VBO): The vertex data itself
- Shader programs are created wieht at least a vertex shader and then activated before use.

---------------------------206-THEORY Vectors Matrices and Uniform Variables------------------------------------------
---------------------------208 CODING Using GLM (OpenGL Maths Library)------------------------------------------

---------------------------209 CODING Transforming Translation------------------------------------------
---------------------------210 CODING Transforming Rotation------------------------------------------
---------------------------211 CODING Transforming Scaling------------------------------------------
---------------------------212 THEORY Interpolation Indexed Draws and Projections------------------------------------------

- Interpolation				- calculates weighted values between vertices during rasterization.
- Indexed					- Draws let us define vertices one then reference them to draw them
- Projection				- Matrices convert view space in to clip space
- Orthographic				- Projections are used for 2D applicationes and dont allow depth perception
- Perspective				- Projections are for 3D applications and create the illusion of depth
- GLM						- has the glm::perspective functio to create perspective matrices


--------------------------- 213 CODING Interpolation ------------------------------------------------------------------

--------------------------- 214 CODING Indexed Draws ------------------------------------------------------------------

--------------------------- 215 CODING Projections ------------------------------------------------------------------

--------------------------- 317 THEORY The Camera and User Input -----------------------------------------------------

- View Matrix requires Position, Direction, Right, and Up vectors
- glm::lookAt handles it for us
- To move camera, alter position on key press.
- Delta time allows consistent speeds across systems
- Turning uses Pitch and Yaw (and Roll in some cases).
- Use pitch and Yaw to calculate new directions vectors
- Compare last and current mouse positions to determine how pitch and yaw change

--------------------------- 318 CODING Camera Input with GLFW ----------------------------------------------------

--------------------------- 319 CODING Camera Movement -----------------------------------------------------------

--------------------------- 320 THEORY Textures and Image Loading ------------------------------------------------

- Texture
- Texture objects
- Mipmaps
- Texture parameters - filters
- Texture parameters - Wrap
- Using stb_image
- Texture samples
- Texture Units

--------------------------- 321 CODING Texture Mapping ---------------------------------------------------------

- incluir libreria de texturizado
https://raw.githubusercontent.com/nothings/stb/master/stb_image.h

--------------------------- 322 THEORY Phong Lighting and Directional Lights -----------------------------------

- Phong Lighting
	- Ambient lighting
	- Diffuse lighting
	- Specuclar lighting

- Types of light
	- Directional Light
	- Point Light
	- Spot Light
	- Area Light

--------------------------- 424 CODING Diffuse Lighting ------------------------------------------------------ 

--------------------------- 426 THEORY Point Lights and Spot Lights ------------------------------------------------------ 


--------------------------- 427 CODING Point Lights ----------------------------------------------------------------------

-------------- 532 THEORY Omnidirectional Shadows Cube Maps and the Geometry Shader -------------

- Omnidirectional shadows use cubemaps to map shadows in all directions.
- Cubemaps are texture consisting of 6 sub-textures
- Cubemap texels are referenced by a direction vector
- Geometry shader handles primitives
- Geometry shader can modify primitives and create entirely new ones... we use it to map to the cubemap from 6 views, allowing only a single shadow pass per light.
- Due to nature cubemaps, no needs for light transform matrix in render pass.
- PCF can use predefined offset directions
- PCF can scale offsets based on viewer distance.
- Need to ensure samplerCubes aren't bound to same texture unit as sampler2D!


------------------------------------ 535 THEORY The Skybox --------------------------------------



*/
