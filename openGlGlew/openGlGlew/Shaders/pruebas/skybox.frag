#version 330

in vec3 TexCoords;

out vec4 colour;

uniform sampleCube skybox;

void main()
{
	colour = texture(skybox, TexCoords);

}
