#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "glm/glm.hpp"
#include "fast_obj.hpp"

class CModel_Loader {
private:
    char* m_szReadingFileName;
    std::vector<glm::vec3> m_vecVertices;
    std::vector<unsigned int> m_vecIndices;
public:
    void CreateLoader(const char* szFileName) noexcept { m_szReadingFileName = (char*)szFileName; };
    void Read(void) noexcept;
    std::vector<glm::vec3>* GetModelVerticesInVector(void) noexcept { return &m_vecVertices; };
    std::vector<unsigned int>* GetModelIndicesInVector(void) noexcept { return &m_vecIndices; };
};
