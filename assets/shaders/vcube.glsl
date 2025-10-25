#version 330 core

layout (location = 0) in vec3 pos;

uniform mat4 mat_View;
uniform mat4 mat_Projection;

void main() {
    gl_Position =  mat_Projection * mat_View * vec4(pos * 0.4, 1.0);
}
