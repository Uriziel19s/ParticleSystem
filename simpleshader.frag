#version 330

in vec3 fColor;

out vec4 vFragColor;

void main()
{
        vFragColor = vec4(fColor, 1);
}
