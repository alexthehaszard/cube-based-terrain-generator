#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();

    void DrawFrame(unsigned int shaderProgram, unsigned int VAO, unsigned int polyCount);
    unsigned int SetupShaders();

    void SetClosed(bool closed) { m_bClosed = closed; }
    bool IsClosed() { return m_bClosed; }
private:
    GLFWwindow* m_pWindow;    
    bool m_bClosed;
};