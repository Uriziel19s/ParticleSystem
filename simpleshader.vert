#version 330
#extension GL_ARB_explicit_uniform_location : require
#extension GL_ARB_shading_language_420pack : require
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

layout(location = 0) uniform mat4 projection;
layout(location = 1) uniform mat4 view;
out vec3 vColor;
void main()
{
    vec4 eyePos = view * vec4(position, 1);
    gl_Position = projection * eyePos;

    vColor = vec3(abs(1/position.x), abs(1/position.y), abs(1/position.z));
    //vColor = vec3(0.0f, 1.0f, 0.0f);
    float dist = length(eyePos.xyz);
    float att = inversesqrt(0.1f*dist);
    gl_PointSize = 2.0f * att;
}
