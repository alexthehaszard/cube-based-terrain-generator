#include <GLFW/glfw3.h>
#include <functional>

#include "window.h"

Window::Window(int width, int height)
{
    glfwInit();
    m_pWindow = glfwCreateWindow(width, height, "My Title", NULL, NULL);

    glfwSetWindowUserPointer(m_pWindow, this);
    glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* window) {
        static_cast<Window*>(glfwGetWindowUserPointer(window))->SetClosed(true);
    });
    SetClosed(false);
}

Window::~Window()
{
    glfwDestroyWindow(m_pWindow);
}

void Window::DrawFrame()
{
    glfwSwapBuffers(m_pWindow);
    glfwPollEvents();
}