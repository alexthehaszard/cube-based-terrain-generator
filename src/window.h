#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();

    void DrawFrame();

    void SetClosed(bool closed) { m_bClosed = closed; }
    bool IsClosed() { return m_bClosed; }
private:
    GLFWwindow* m_pWindow;    
    bool m_bClosed;
};