#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "glm/glm.hpp"

class CModel_Loader {
private:
    char* m_szReadingFileName;
    std::vector<glm::vec3> m_vecVertices;
public:
    void CreateLoader(const char* szFileName) noexcept { m_szReadingFileName = (char*)szFileName; };
    void ReadVertices(void) noexcept;
};
