#version 460 core
layout (location = 0) in vec4 vertex;

out vec2 TexCoords;

void main()
{
    gl_Position = vec4(vertex.x, 0.0, vertex.y, 1.0);
    TexCoords = vertex.zw;
} 