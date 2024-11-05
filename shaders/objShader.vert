#version 460 core

layout (location = 1) in vec3 vPos;

void main() {
    gl_Position = vec4(vPos, 1.0f);
}