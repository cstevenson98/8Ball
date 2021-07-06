#shader vertex 
#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 aTexCoord;
uniform mat4 proj;

out vec2 TexCoord;
void main()
{
	gl_Position = proj * vec4(position, 1.);
	TexCoord = aTexCoord;
};

///////////////////////////////////////////////////////////

#shader fragment
#version 410 core

layout(location = 0) out vec4 colour;
uniform vec4 u_Colour;

in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
	gl_FragColor = texture(ourTexture, TexCoord);
};
