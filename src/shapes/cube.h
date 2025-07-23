#include <stdafx.h>
#include "object.h"

class Cube : public Object
{
public:
    Cube(const glm::vec3& coords, const glm::vec3& dimensions);
    ~Cube();

private:
    std::array<glm::vec3, 4> GetOppositeFace(const std::array<glm::vec3, 4>& face, float distance, int index);
};