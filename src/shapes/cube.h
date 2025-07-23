#include <stdafx.h>
#include "object.h"

class Cube : public Object
{
public:
    Cube(glm::vec3 coords, glm::vec3 dimensions);
    ~Cube();
};