#pragma once

#include <stdafx.h>

#include "object.h"

class Poly : public Object
{
public:
    Poly(std::array<glm::vec3, 3> coords, std::array<glm::vec2, 3> texCoords);
    ~Poly();
};