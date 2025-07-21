#include "stdafx.h"

class Window
{
public:
    Window(int width, int height);
    ~Window();

    /**
     * Window::DrawFrame
     * @param VAO Vertex array object contains vertices of the triangles to draw
     * @param polyCount Number of polygons to draw
     */
    void DrawFrame(unsigned int VAO, unsigned int polyCount);

    void SetClosed(bool closed) { m_bClosed = closed; }
    bool IsClosed() { return m_bClosed; }
private:
    GLFWwindow* m_pWindow;    
    bool m_bClosed;
};