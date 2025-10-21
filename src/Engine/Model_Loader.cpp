#include "Model_Loader.hpp"

void CModel_Loader::Read(void) noexcept {
    if (!m_szReadingFileName)
        return;

    fastObjMesh* mesh = fast_obj_read(m_szReadingFileName);
    if (!mesh)
        return;

    m_vecVertices.clear();
    m_vecIndices.clear();

    // Positions
    for (unsigned int i = 0; i < mesh->position_count; ++i) {
        glm::vec3 vertex(
            mesh->positions[i * 3 + 0],
            mesh->positions[i * 3 + 1],
            mesh->positions[i * 3 + 2]
        );
        m_vecVertices.push_back(vertex);
    }

    // Indices
    for (unsigned int i = 0; i < mesh->index_count; ++i) {
        m_vecIndices.push_back(mesh->indices[i].p);
    }

    fast_obj_destroy(mesh);
}
