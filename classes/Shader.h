#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Camera.h"

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void use(); 
	void setFromCamera(const Camera & camera, float screen_width, float screen_height);

	inline void setMat4(const std::string& name, float* matrix);

	template<class ... Types>
	inline void setBool(const std::string& name, Types ... values) const;

	template<class ... Types>
	inline void setInt(const std::string& name, Types ... values) const;

	template<class ... Types>
	inline void setFloat(const std::string& name, Types ... values) const;

	template<class T, int N>
	inline void setFloat(const std::string& name, glm::vec<N, T> vec) const;
};

template<class ...Types>
inline void Shader::setBool(const std::string & name, Types ...values) const
{
	if constexpr (sizeof...(values) == 1)
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)values...);
	if constexpr (sizeof...(values) == 2)
		glUniform2i(glGetUniformLocation(ID, name.c_str()), (int)values...);
	if constexpr (sizeof...(values) == 3)
		glUniform3i(glGetUniformLocation(ID, name.c_str()), (int)values...);
	if constexpr (sizeof...(values) == 4)
		glUniform4i(glGetUniformLocation(ID, name.c_str()), (int)values...);
}

template<class ...Types>
inline void Shader::setInt(const std::string & name, Types ...values) const
{
	if constexpr (sizeof...(values) == 1)
		glUniform1i(glGetUniformLocation(ID, name.c_str()), values...);
	if constexpr (sizeof...(values) == 2)
		glUniform2i(glGetUniformLocation(ID, name.c_str()), values...);
	if constexpr (sizeof...(values) == 3)
		glUniform3i(glGetUniformLocation(ID, name.c_str()), values...);
	if constexpr (sizeof...(values) == 4)
		glUniform4i(glGetUniformLocation(ID, name.c_str()), values...);
}

template<class ...Types>
inline void Shader::setFloat(const std::string & name, Types ...values) const
{
	if constexpr (sizeof...(values) == 1)
		glUniform1f(glGetUniformLocation(ID, name.c_str()), values...);
	if constexpr (sizeof...(values) == 2)
		glUniform2f(glGetUniformLocation(ID, name.c_str()), values...);
	if constexpr (sizeof...(values) == 3)
		glUniform3f(glGetUniformLocation(ID, name.c_str()), values...);
	if constexpr (sizeof...(values) == 4)
		glUniform4f(glGetUniformLocation(ID, name.c_str()), values...);
}

template<class T, int N>
inline void Shader::setFloat(const std::string& name, glm::vec<N, T> vec) const
{
	if constexpr (N == 1)
		glUniform1f(glGetUniformLocation(ID, name.c_str()), vec);
	if constexpr (N == 2)
		glUniform2f(glGetUniformLocation(ID, name.c_str()), vec.x, vec.y);
	if constexpr (N == 3)
		glUniform3f(glGetUniformLocation(ID, name.c_str()), vec.x, vec.y, vec.z);
	if constexpr (N == 4)
		glUniform4f(glGetUniformLocation(ID, name.c_str()), vec.x, vec.y, vec.z, vec.w);
}

inline void Shader::setMat4(const std::string& name, float* matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, matrix);
}

#endif // !SHADER_H