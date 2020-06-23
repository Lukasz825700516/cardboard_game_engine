#version 330 core

uniform sampler2D u_textures[16];

in vec2 vp_uv;
flat in int vp_texture;

out vec4 vo_color;

void main() {
	vec4 texture_color;

	switch (vp_texture) {
		case 0: texture_color = texture(u_textures[0], vp_uv); break;
		case 1: texture_color = texture(u_textures[1], vp_uv); break;
		case 2: texture_color = texture(u_textures[2], vp_uv); break;
		case 3: texture_color = texture(u_textures[3], vp_uv); break;
		case 4: texture_color = texture(u_textures[4], vp_uv); break;
		case 5: texture_color = texture(u_textures[5], vp_uv); break;
		case 6: texture_color = texture(u_textures[6], vp_uv); break;
		case 7: texture_color = texture(u_textures[7], vp_uv); break;
		case 8: texture_color = texture(u_textures[8], vp_uv); break;
		case 9: texture_color = texture(u_textures[9], vp_uv); break;
		case 10: texture_color = texture(u_textures[10], vp_uv); break;
		case 11: texture_color = texture(u_textures[11], vp_uv); break;
		case 12: texture_color = texture(u_textures[12], vp_uv); break;
		case 13: texture_color = texture(u_textures[13], vp_uv); break;
		case 14: texture_color = texture(u_textures[14], vp_uv); break;
		case 15: texture_color = texture(u_textures[15], vp_uv); break;
	}

	vo_color = texture_color;
}
