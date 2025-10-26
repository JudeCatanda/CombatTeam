#include "Texture.hpp"
#include "Window.hpp"

#undef LOG_ERROR
#define LOG_ERROR(fmt, ...) std::printf("[ERROR] " fmt "\n", ##__VA_ARGS__)
#undef LOG_INFO
#define LOG_INFO(fmt, ...) std::printf("[INFO] " fmt "\n", ##__VA_ARGS__)

void CTexture::loadFile(std::string filename) {
  Flip(true);
  m_puszBytes = stbi_load(filename.c_str(), &m_nWidth, &m_nHeight, &m_nChannels, 0);
  if (!m_puszBytes)
    Throw_Error(nullptr, "Cannot Load Texture!");
}

void CTexture::Create(std::string filename, GLenum target, GLint internal_format, GLenum format) {
  if (this->load_file_already)
    loadFile(filename);

  glGenTextures(1, &m_nHandle);
  glBindTexture(target, this->m_nHandle);
  m_Target = target;
  if (this->use_default_params) {
    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
  }

  if(target == GL_TEXTURE_2D) {
      glTexImage2D(target, 0, internal_format, m_nWidth, m_nHeight, 0, format, GL_UNSIGNED_BYTE, m_puszBytes);
    glGenerateMipmap(target);
  }

  stbi_image_free(m_puszBytes);
  glBindTexture(target, 0);
}

void CTexture::Bind() { glBindTexture(m_Target, m_nHandle); }

void CTexture::BindAndSetActive(GLenum idx) {
  glActiveTexture(idx);
  Bind();
}

void CTexture::Unbind() { glBindTexture(m_Target, 0); }
