#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

#include <iostream>

class Texture
{
public:
	unsigned int ID;

	Texture(const char * path, int format);
	~Texture();

	void Bind() const;
};

#endif // !TEXTURE_H