#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();

    void DrawFrame();

    bool is_closed;
private:
    GLFWwindow* m_pWindow;
};