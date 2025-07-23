#pragma once

#include <stdafx.h>

#include "object.h"

class Square : public Object
{
public:
    Square(const std::array<glm::vec3, 4>& coords, const std::array<glm::vec2, 4>& texCoords);
    ~Square();

};