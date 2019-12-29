#ifndef BOX_H
#define BOX_H

#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Texture.h"

class Box
{
	static const float vertices[];
	static const unsigned int indices[];
	
	static unsigned int VBO, VAO, EBO;
	static bool isInitialised;

	glm::mat4 model;
	glm::mat4 position;
	glm::mat4 rotation;
	glm::mat4 scale;

	Shader* shader;

	bool recalculate = false;
public:
	static void Initialize();
	static void Terminate();

	Box(glm::vec3 _position = glm::vec3(0.0f), glm::vec3 size = glm::vec3(1.0f), float angle = 0.0f, glm::vec3 rotationAxes = glm::vec3(1.0f));

	glm::mat4& GetModel();
	glm::vec3 GetPosition();

	void Rotate(float angle, glm::vec3 axes);
	void Scale(glm::vec3 size);
	void Translate(glm::vec3 _position);

	void SetRotation(float angle, glm::vec3 axes);
	void SetScale(glm::vec3 size);
	void SetPosition(glm::vec3 _position);

	void SetShader(Shader& _shader);
	void AddTexture(const Texture& texture, unsigned int textureNo = 0);
	void Draw();
};

#endif // !BOX_H