#pragma once

#include <stdafx.h>

#include "object.h"

class Square : public Object
{
public:
    Square(std::array<glm::vec3, 4> coords, std::array<glm::vec2, 4> texCoords);
    ~Square();

};