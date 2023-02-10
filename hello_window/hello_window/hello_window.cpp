#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<iostream>


// funciton declaration
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
	std::cout << "Starting progam!" << std::endl;

	// initialize glfw
	std::cout << "Initializing GLFW..." << std::endl;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create window 
	std::cout << "Creating window..." << std::endl;
	GLFWwindow* window = glfwCreateWindow(800, 600, "MY First Window!", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// initialize glad
	std::cout << "Initializing GLAD..." << std::endl;
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initilize GLAD" << std::endl;
		return -1;
	}


	// set viewport
	std::cout << "Setting view port..." << std::endl;
	glViewport(0, 0, 800, 600);

	// register frame resize callback
	std::cout << "Registering frame resize callback..." << std::endl;
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// rendering loop
	std::cout << "Runnning rendering loop..." << std::endl;
	while (!glfwWindowShouldClose(window)) {
		// check for input
		processInput(window);

		// rendering commands
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // fills buffer color with this color (gray) whenever the color buffer is cleared
		glClear(GL_COLOR_BUFFER_BIT); // clear color buffer


		// swap front and back buffers
		glfwSwapBuffers(window);

		// poll for events
		glfwPollEvents();
	}

	// clean up glfw resources
	std::cout << "Cleaning up GLFW resources..." << std::endl;
	glfwTerminate();


	std::cout << "Finished Program!" << std::endl;
	return 0;
}


// resize window callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	std::cout << "Resizing window...\tNew Size: (" << width << ", " << height << ")" << std::endl;
	glViewport(0, 0, width, height);
}

// process input callback
void processInput(GLFWwindow* window) {

	// close window on escape key press
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		std::cout << "ESC pressed! Closing Window..." << std::endl;
		glfwSetWindowShouldClose(window, true);
	}
	
}