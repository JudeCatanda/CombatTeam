#include "Core/Instance.hpp"

class CCube : public IInstance3D {
private:
    std::vector<glm::vec3>* m_vecModelVertices;
    std::vector<unsigned int>* m_vecModelIndices;
    CModel_Loader m_Loader;
public:
    void Create() override;
    void Draw(void) override;
    void Update() override;
};

