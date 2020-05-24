#version 330 core

layout (location = 0) in vec2 v_pos;
layout (location = 1) in vec2 v_uv;

out vec2 vp_uv;

uniform mat4 camera_transform;
uniform vec2 camera_position;

void main() {
	gl_Position = camera_transform * (vec4(v_pos, 0.0, 1.0) - vec4(camera_position, 0.0, 0.0));

	vp_uv = v_uv;
}
