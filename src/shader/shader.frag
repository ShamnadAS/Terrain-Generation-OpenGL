#version 460 core
out vec4 FragColor;

in float Height;

void main()
{
	float h = Height * 5.0;
	FragColor = vec4(h, h, h, 1.0);
}
