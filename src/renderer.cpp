#include "renderer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

unsigned int Renderer::GenerateVertexArrayObject()
{
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO); 

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_ObjectVertexList.size(), &m_ObjectVertexList[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    return VAO;
}

unsigned int Renderer::LoadTextureFromFile(std::string filepath)
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return texture;
}

unsigned int Renderer::GetPolyCount()
{
    return m_ObjectVertexList.size() / 5;
}

void Renderer::AddObject(const Object& o)
{
    m_Objects.push_back(o);

    m_ObjectVertexList.clear();
    for (const auto& object : m_Objects)
    {
        std::shared_ptr<std::vector<float>> pObjectVertexList = object.GetVertexArray();
        m_ObjectVertexList.insert(m_ObjectVertexList.end(), pObjectVertexList->begin(), pObjectVertexList->end());
    }
}