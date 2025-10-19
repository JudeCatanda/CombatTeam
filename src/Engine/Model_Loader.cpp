#include "Model_Loader.hpp"

void CModel_Loader::ReadVertices(void) noexcept {
    if(m_szReadingFileName == NULL)
        return;

    std::ifstream file(m_szReadingFileName);
    if(!file.is_open())
        return;

    std::string current_line;
    while(std::getline(file, current_line)) {
        std::cout << current_line << std::endl;
    }
};
