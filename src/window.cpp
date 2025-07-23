#include "window.h"

Window::Window(int width, int height)
{
    // Initialze GLFW, set some GLFW settings and create the window
    if (!glfwInit()) exit(1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_pWindow = glfwCreateWindow(width, height, "My Title", NULL, NULL);

    // Set context to new window, then initialize GLEW
    glfwMakeContextCurrent(m_pWindow);
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Glew failed to initialize\n";
        exit(1);
    }

    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (glfwRawMouseMotionSupported()) glfwSetInputMode(m_pWindow, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

    // Add a pointer to this class to the window, then set the "closed" callback
    // which sets this window class to closed
    glfwSetWindowUserPointer(m_pWindow, this);
    glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* window) {
        static_cast<Window*>(glfwGetWindowUserPointer(window))->SetClosed(true);
    });
    SetClosed(false);
}

Window::~Window()
{
    glfwDestroyWindow(m_pWindow);
    glfwTerminate();
}

void Window::DrawFrame(unsigned int VAO, unsigned int polyCount, unsigned int texture)
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3 * polyCount);

    glfwSwapBuffers(m_pWindow);
    glfwPollEvents();
}

int Window::GetKey(int key)
{
    return glfwGetKey(m_pWindow, key);
}

glm::vec2 Window::GetCursorPos()
{
    double x, y;
    glfwGetCursorPos(m_pWindow, &x, &y);
    return glm::vec2{x, y};
}

GLFWwindow* Window::GetWindow()
{
    return m_pWindow;
}