#version 330
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;


out vec3 gColor;
void main()
{

    gl_Position = vec4(position, 1);
    //gColor = color;

    gColor = vec3(0.0f, 1.0f, 0.0f);
}
