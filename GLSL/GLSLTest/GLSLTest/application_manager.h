#pragma once

class ApplicationManager : private utility::Noncopyable
{
public:
	ApplicationManager()
	{
		glfwInit();

		window_ = glfwCreateWindow(640, 480, "OpenGL", nullptr, nullptr);

		glfwMakeContextCurrent(window_);

		glewInit();
	}

	~ApplicationManager()
	{
		glfwTerminate();
	}

	void Run()
	{
		while (!glfwWindowShouldClose(window_))
		{
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

			glClear
			(
				GL_COLOR_BUFFER_BIT |
				GL_DEPTH_BUFFER_BIT |
				GL_STENCIL_BUFFER_BIT
			);

			glfwSwapBuffers(window_);
			glfwPollEvents();
		}
	}

private:
	GLFWwindow* window_ = nullptr;
};