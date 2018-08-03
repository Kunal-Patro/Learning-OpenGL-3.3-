#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
using namespace std;
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
void process_input(GLFWwindow* window) {
	//-----Press esc to exit while runtime----
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	//-----Press G to change screen color to green while runtime----
	else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
	}
	//-----Press R to change screen color to red while runtime-----
	else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	}
	//-----Press B to change screen color to blue while runtime-----
	else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	}
}
int main() {
	//-------Initialize and configure hints--------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//-------Creating window--------
	GLFWwindow* window = glfwCreateWindow(800, 600, "Learning OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//-------Load all opengl functions :GLAD--------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initalize GLAD" << std::endl;
		return -1;
	}
	//-------Registering callback function--------
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//-------Render Loop--------
	while (!glfwWindowShouldClose(window)) {
		//---Input Handeling---
		process_input(window);
		//---Rendering Code---
		glClear(GL_COLOR_BUFFER_BIT);
		//---Swap buffers(Double Buffers) and poll IO events--- 
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//-------Deallocating all memory and resources--------
	glfwTerminate();
	return 0;
}