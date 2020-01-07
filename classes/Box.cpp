#include "Box.h"

unsigned int Box::VAO = 0;
unsigned int Box::VBO = 0;
unsigned int Box::EBO = 0;
bool Box::isInitialised = false;

const float Box::vertices[] = {
	// positions          // normals           // texture coords
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
	
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
	
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
};
const unsigned int Box::indices[] = {
		0, 1, 2, // front
		0, 2, 3,

		4, 5, 6, // back
		4, 6, 7,

		8,  9, 10, // up
		8, 10, 11,

		12, 13, 14, // down
		12, 14, 15,

		0, 3, 4, // left
		3, 4, 7,

		1, 2, 5, // right
		2, 5, 6
};

void Box::Initialize()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof indices, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	isInitialised = true;
}

void Box::Terminate()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);
}

Box::Box(glm::vec3 _position, glm::vec3 size, float angle, glm::vec3 rotationAxes)
{	
	if (!isInitialised) Initialize();
	scale = glm::scale(glm::mat4(1.0f), size);
	rotation = glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotationAxes);
	position = glm::translate(glm::mat4(1.0f), _position);
	model = position * rotation * scale * glm::mat4(1.0f);
	shader = nullptr;
}

glm::mat4 & Box::GetModel()
{
	if(recalculate)
	{
		model = position * rotation * scale * glm::mat4(1.0f);
		recalculate = false;
	}
	return model;
}

glm::vec3 Box::GetPosition()
{
	return glm::vec3(position[3][0], position[3][1], position[3][2]);
}

void Box::Rotate(float angle, glm::vec3 axes)
{
	rotation = glm::rotate(rotation, glm::radians(angle), axes);
	recalculate = true;
}

void Box::Scale(glm::vec3 size)
{
	scale = glm::scale(scale, size);
	recalculate = true;
}

void Box::Translate(glm::vec3 _position)
{
	position = glm::translate(position, _position);
	recalculate = true;
}

void Box::SetRotation(float angle, glm::vec3 axes)
{
	rotation = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axes);
	recalculate = true;
}

void Box::SetScale(glm::vec3 size)
{
	scale = glm::scale(glm::mat4(1.0f), size);
	recalculate = true;
}

void Box::SetPosition(glm::vec3 _position)
{
	position = glm::translate(glm::mat4(1.0f), _position);
	recalculate = true;
}

void Box::SetShader(Shader & _shader)
{
	shader = &_shader;
}

void Box::AddTexture(const Texture & texture, unsigned int textureNo)
{
	shader->use();
	glActiveTexture(GL_TEXTURE0 + textureNo);
	texture.Bind();
}

void Box::Draw()
{	
	if (recalculate)
	{
		model = position * rotation * scale * glm::mat4(1.0f);
		recalculate = false;
	}
	shader->use();
	glBindVertexArray(VAO);
	shader->setMat4("model", glm::value_ptr(model));
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
