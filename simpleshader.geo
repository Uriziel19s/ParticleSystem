#version 330
#extension GL_ARB_explicit_uniform_location : require
#extension GL_ARB_shading_language_420pack : require
layout (points) in;
layout (triangle_strip, max_vertices = 4) out;
in vec3 gColor[];
out vec3 fColor;

layout(location = 0) uniform mat4 projection;
layout(location = 1) uniform mat4 view;

void build_house(vec4 position)
{
    mat4 proView = projection * view;
    gl_Position = proView * (position + vec4(-0.2, -0.2, -0.2, 0.0));    // 1:lewy dolny
    EmitVertex();
    fColor = vec3(abs(1/position.x), abs(1/position.y), abs(1/position.z));
    gl_Position = proView * (position + vec4( 0.2, -0.2, -0.2, 0.0));    // 2:prawy dolny
    EmitVertex();
    fColor = vec3(abs(1/position.x), abs(1/position.y), abs(1/position.z));
    gl_Position = proView * (position + vec4(-0.2,  0.2, -0.2, 0.0));    // 3:lewy górny
    EmitVertex();
    fColor = vec3(abs(1/position.x), abs(1/position.y), abs(1/position.z));
    gl_Position = proView * (position + vec4( 0.2,  0.2, -0.2, 0.0));    // 4:prawy górny
    EmitVertex();
    fColor = vec3(abs(1/position.x), abs(1/position.y), abs(1/position.z));
    EndPrimitive();
}

void main() {
build_house(gl_in[0].gl_Position);
}
