#version 330 core

in vec2 vp_uv;
out vec4 vo_color;

void main() {
	vo_color = vec4(vp_uv, 1.0, 1.0);
}
