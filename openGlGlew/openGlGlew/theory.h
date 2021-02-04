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



*/
