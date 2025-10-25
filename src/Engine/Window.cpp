#include "Window.hpp"

void CWindow::Create(const char* szTitle, int nWidth, int nHeight) {
  if(!glfwInit())
      Throw_Error(m_Handle, "Cannot initialize GLFW");

  m_Handle = glfwCreateWindow(nHeight, nWidth, szTitle, nullptr, nullptr);
  m_Size = glm::ivec2(nWidth, nHeight);

  if(m_Handle == nullptr)
   Throw_Error(m_Handle, "Cannot Create Window!");

  glfwMakeContextCurrent(m_Handle);

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
      Throw_Error(m_Handle, "Failed to communicate with your drivers");

  m_KeyboardState.Init();
};

GLFWwindow* CWindow::GetHandle(void) {
  return m_Handle;
}

glm::ivec2 CWindow::GetSize() {
    glm::ivec2 size;
    glfwGetWindowSize(m_Handle, &size.x, &size.y);
    return size;
}

int CWindow::ShouldClose() {
  return glfwWindowShouldClose(m_Handle);
};

void CWindow::Destroy() {
  glfwDestroyWindow(m_Handle);
}

bool CWindow::IsKeyPressed(int nKey) {
  return (glfwGetKey(m_Handle, nKey) == GLFW_PRESS) ? true : false;
}

float CWindow::GetAspectRatio() {
  glfwGetWindowSize(m_Handle, &m_Size.x, &m_Size.y);
  m_flAspectRatio = (float)m_Size.x / (float)m_Size.y;
  return m_flAspectRatio;
}

void CWindow::SetViewport() {
  glm::ivec2 ViewportSize = GetSize();
  glViewport(0, 0, ViewportSize.x, ViewportSize.y);
}

bool CWindow::IsKeyReleased(int nKey) {
  return (glfwGetKey(m_Handle, nKey) == GLFW_RELEASE) ? true : false;
}

void CWindow::SubmitKeyCallback(GLFWkeyfun callback) {
  glfwSetKeyCallback(m_Handle, callback);
}
  
void CWindow::SetFullScreen(bool bFullScreen) {
  const GLFWvidmode* VideoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());  //(returns int)

  int LastSizeW, LastSizeH, LastPosX, LastPosY; //implement later
  glfwGetWindowPos(m_Handle, &LastPosX, &LastPosY);
  glfwGetWindowSize(m_Handle, &LastSizeW, &LastSizeH);

  if(bFullScreen) {
    glfwSetWindowMonitor(m_Handle, glfwGetPrimaryMonitor(), 0, 0, VideoMode->width, VideoMode->height, VideoMode->refreshRate);
  }
  if(!bFullScreen) {        
    glfwSetWindowMonitor(m_Handle, nullptr, LastPosX, LastPosY, LastSizeW, LastSizeH, GLFW_DONT_CARE);
  }

  m_bFullScreen = bFullScreen;
};

bool CWindow::CheckKeyState(int nKey) {
  m_KeyboardState.Current = glfwGetKey(m_Handle, nKey);
  bool retValue = false;
  if(m_KeyboardState.Current == GLFW_PRESS && m_KeyboardState.Prev[nKey] == GLFW_RELEASE)
    retValue = true;
  m_KeyboardState.Prev[nKey] = m_KeyboardState.Current;
  return retValue;
};

void Throw_Error(GLFWwindow *handle, const char *message) {
    std::cout << message << std::endl;
};
