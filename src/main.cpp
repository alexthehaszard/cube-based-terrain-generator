#include <iostream>

#include <GLFW/glfw3.h>

#include "window.h"

int main() 
{
    std::unique_ptr<Window> pWindow = std::make_unique<Window>(640, 480);

    // Game loop
    while (!pWindow->IsClosed())
    {
        pWindow->DrawFrame();
    }

    return 0;
}