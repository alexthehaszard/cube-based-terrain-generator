#pragma once

#include "stdafx.h"

class Object
{
public:
    std::shared_ptr<std::vector<float>> GetVertexArray() const { return m_pVertexList; }
protected:
    std::shared_ptr<std::vector<float>> m_pVertexList;
};