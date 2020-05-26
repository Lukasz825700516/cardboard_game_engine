#version 330 core

uniform sampler2D u_texture;

in vec2 vp_uv;
out vec4 vo_color;

void main() {
	vo_color = texture(u_texture, vp_uv);
}
