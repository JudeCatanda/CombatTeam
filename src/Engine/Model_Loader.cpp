#include "Model_Loader.hpp"

void CModel_Loader::ReadVertices(void) noexcept {
    if (m_szReadingFileName == nullptr)
        return;

    std::ifstream ifsModelFile(m_szReadingFileName);
    if (!ifsModelFile.is_open())
        return;

    std::string strLine;
    std::string strToken;

    while (std::getline(ifsModelFile, strLine)) {
        std::istringstream issLine(strLine);

        while (issLine >> strToken) {
            if (strToken == "v") {
                float fX, fY, fZ;
                issLine >> fX >> fY >> fZ;
                m_vecVertices.push_back(glm::vec3(fX, fY, fZ));
            }
        }
    }
}
