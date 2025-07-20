#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();

    /**
     * Window::DrawFrame
     * @param shaderProgram Shader program used to draw the frame
     * @param VAO Vertex array object contains vertices of the triangles to draw
     * @param polyCount Number of polygons to draw
     */
    void DrawFrame(unsigned int shaderProgram, unsigned int VAO, unsigned int polyCount);
    
    /**
     * Window::SetupShaders
     * @return a basic shader program containing a vertex and fragment shader
     */
    unsigned int SetupShaders();

    void SetClosed(bool closed) { m_bClosed = closed; }
    bool IsClosed() { return m_bClosed; }
private:
    GLFWwindow* m_pWindow;    
    bool m_bClosed;
};