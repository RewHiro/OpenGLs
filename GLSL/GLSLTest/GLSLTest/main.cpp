#include "stdafx.h"

int main()
{
	GLFWwindow* window;

	glfwInit();

	window = glfwCreateWindow(640, 480, "OpenGL", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		glClear
		(
			GL_COLOR_BUFFER_BIT |
			GL_DEPTH_BUFFER_BIT |
			GL_STENCIL_BUFFER_BIT
		);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}