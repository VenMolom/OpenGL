#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include <iostream>
#include <complex>

#include "classes/Shader.h"
#include "classes/Camera.h"
#include "classes/Texture.h"
#include "classes/Box.h"

// prototypes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const unsigned int NR_POINT_LIGHTS = 4;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

// time
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// light
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main() 
{
	// initialization
	glfwInit();
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// window creation
	int screenWidth = 800, screenHeight = 600;
	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "OpenGL", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// callbacks
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// glad loading
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}


	// boxes
	Box object;
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	Box light(lightPos, glm::vec3(0.2f));
	glm::vec3 pointLightPositions[] = {
		glm::vec3(0.7f,  0.2f,  2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f,  2.0f, -12.0f),
		glm::vec3(0.0f,  0.0f, -3.0f)
	};


	//texture
	Texture diffuseMap("textures/container2.png", GL_RGBA);
	Texture specularMap("textures/container2_specular.png", GL_RGBA);


	// shader program
	Shader shaderProgram("shaders/shader.vert", "shaders/shader.frag");
	shaderProgram.use();

	// material uniforms
	shaderProgram.setInt("material.diffuse", 0);
	shaderProgram.setInt("material.specular", 1);
	shaderProgram.setFloat("material.shininess", 64.0f);

	// dirLight uniforms
	shaderProgram.setFloat("dirLight.direction", -0.2f, -1.0f, -0.3f);
	shaderProgram.setFloat("dirLight.ambient", 0.05f, 0.05f, 0.05f);
	shaderProgram.setFloat("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
	shaderProgram.setFloat("dirLight.specular", 0.5f, 0.5f, 0.5f);

	// pointLights uniforms
	for (int i = 0; i < NR_POINT_LIGHTS; ++i)
	{
		std::string position = std::to_string(i);
		shaderProgram.setFloat("pointLights[" + position + "].position", pointLightPositions[i]);

		shaderProgram.setFloat("pointLights[" + position + "].ambient", 0.00f, 0.05f, 0.00f);
		shaderProgram.setFloat("pointLights[" + position + "].diffuse", 0.0f, 0.8f, 0.0f);
		shaderProgram.setFloat("pointLights[" + position + "].specular", 0.0f, 1.0f, 0.0f);

		shaderProgram.setFloat("pointLights[" + position + "].constant", 1.0f);
		shaderProgram.setFloat("pointLights[" + position + "].linear", 0.09f);
		shaderProgram.setFloat("pointLights[" + position + "].quadratic", 0.032f);
	}

	// spotLight uniforms
	shaderProgram.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	shaderProgram.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));

	shaderProgram.setFloat("spotLight.ambient", 0.0f, 0.0f, 0.0f);
	shaderProgram.setFloat("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
	shaderProgram.setFloat("spotLight.specular", 1.0f, 1.0f, 1.0f);

	shaderProgram.setFloat("spotLight.constant", 1.0f);
	shaderProgram.setFloat("spotLight.linear", 0.09f);
	shaderProgram.setFloat("spotLight.quadratic", 0.032f);
	

	Shader lampShader("shaders/shader.vert", "shaders/shaderLamp.frag");

	object.SetShader(shaderProgram);
	light.SetShader(lampShader);
	
	object.AddTexture(diffuseMap, 0);
	object.AddTexture(specularMap, 1);
	//object.AddTexture(container, 0);
	//object.AddTexture(face, 1);


	glEnable(GL_DEPTH_TEST);
	// game loop
	while (!glfwWindowShouldClose(window))
	{
		// delta time
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// process inputs
		processInput(window);
		
		// clear
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//light.SetPosition((glm::vec3)(glm::rotate(glm::mat4(1.0f), glm::radians(100.0f * deltaTime), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(light.GetPosition(), 1.0f)));
		//std::cout << light.GetPosition().x << " " << light.GetPosition().y << " " << light.GetPosition().z << std::endl;

		// lightColor
		/*glm::vec3 lightColor;
		lightColor.x = sin(glfwGetTime() * 2.0f);
		lightColor.y = sin(glfwGetTime() * 0.7f);
		lightColor.z = sin(glfwGetTime() * 1.3f);

		glm::vec3 diffuseColor = glm::vec3(0.5f) * lightColor;
		glm::vec3 ambientColor = glm::vec3(0.2f) * lightColor;

		shaderProgram.use();
		shaderProgram.setFloat("light.ambient", ambientColor);
		shaderProgram.setFloat("light.diffuse", diffuseColor);*/

		// set program
		shaderProgram.setFromCamera(camera, SCR_WIDTH, SCR_HEIGHT);
		lampShader.setFromCamera(camera, SCR_WIDTH, SCR_HEIGHT);

		//box.Rotate(50.0f * deltaTime, glm::vec3(1.0f, 1.0f, 1.0f));
		//box.SetPosition(glm::vec3(0.0f, sin(glfwGetTime()), 0.0f));

		for (int i = 0; i < 10; ++i)
		{
			object.SetPosition(cubePositions[i]);
			object.SetRotation(20.0f * i, glm::vec3(1.0f, 0.3f, 0.5f));
			object.Draw();
		}

		for (int i = 0; i < NR_POINT_LIGHTS; ++i)
		{
			light.SetPosition(pointLightPositions[i]);
			light.Draw();
		}

		// buffer swap and pool events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Box::Terminate();
}
	// terminate
	glfwTerminate();
	return 0;
}

// resize callback
void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// scroll callback
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

// mouse callback
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	static float lastX = xpos, lastY = ypos;

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// input processor
void processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}