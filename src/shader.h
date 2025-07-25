#pragma once

#include "stdafx.h"

class Shader
{
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use();
    void SetBool(const std::string& name, bool value) const;  
    void SetInt(const std::string& name, int value) const;   
    void SetFloat(const std::string& name, float value) const;
    void SetMat4(const std::string& name, const glm::mat4& matrix) const;

    unsigned int ID;
};
  