#version 330 core
out vec4 FragColor;

void main()
{
	FragColor = vec4(1.0f);
	//FragColor = mix(texture(texture1, TexCoords), texture(texture2, TexCoords), 0.2f);
}