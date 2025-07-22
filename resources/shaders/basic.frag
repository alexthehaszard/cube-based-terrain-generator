#version 330 core

out vec4 FragColor;

void main()
{
   FragColor = vec4(gl_PointCoord.x, gl_PointCoord.y, 1.0f, 1.0f);
}