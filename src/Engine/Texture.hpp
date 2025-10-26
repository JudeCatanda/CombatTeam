#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"
#include <iostream>
#include <vector>
#include <assert.h>
#include "stb_image.h"

//-----------------------------------------------------------------------------
// Purpose: A Texture/Sampler2D class for opengl
//-----------------------------------------------------------------------------
class CTexture {
private:
  unsigned int m_nHandle;
  unsigned char* m_puszBytes;
  int m_nWidth, m_nHeight, m_nChannels;
  GLenum m_Target;
  GLenum m_nIndex;

  void loadFile(std::string filename);
public:
  CTexture() = default;
  void Create(std::string filename, GLenum target, GLint internal_format, GLenum format);
  void Bind();
  void BindAndSetActive(GLenum index);
  void Unbind();

  void Flip(bool cond) noexcept {
    stbi_set_flip_vertically_on_load(cond);
  };

  glm::vec2 GetSize() const noexcept {
      return glm::vec2(m_nWidth, m_nHeight);
  }

  bool IsImageValid();

  //it ask's for the file. if false load other ways like fbo's
  bool load_file_already = true;
  bool use_default_params = true;
};
