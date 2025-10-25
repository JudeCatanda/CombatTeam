#version 330 core

layout (location = 0) in vec3 pos;

uniform mat4 mat_View;
uniform mat4 mat_Projection;
uniform mat4 mat_Model;

void main() {
    gl_Position =  mat_Projection * mat_View * mat_Model * vec4(pos, 1.0);
}
