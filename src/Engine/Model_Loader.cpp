#include "Model_Loader.hpp"

void CModel_Loader::ReadVertices(void) noexcept {
    if(m_szReadingFileName == NULL)
        return;

    std::ifstream file(m_szReadingFileName);
    if(!file.is_open())
        return;

    std::string current_line;
    while(std::getline(file, current_line)) {

        struct Strings line_split = String_split(current_line.c_str(), ' ');
        for(int i = 0; i < line_split.num; i++) {
            std::cout << line_split.data[i] << std::endl;
        }

    }
};
