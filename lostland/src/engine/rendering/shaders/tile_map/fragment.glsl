#version 460 core

out vec4 FragColor;

in vec2 UV;
uniform sampler2D atlas;
uniform usampler2D tiles;
uniform uvec2 atlas_size;
uniform uvec2 grid_size;

void main() {
	uint tile = texture(tiles, UV).r;
	vec2 tile_pos = vec2(tile%atlas_size.x, atlas_size.y-1-tile/atlas_size.x) / atlas_size;
	vec2 tile_UV = vec2(mod(UV.x,(1/float(grid_size.x))), mod(UV.y,(1/float(grid_size.y)))) * grid_size;

	vec2 final_UV = tile_pos + tile_UV / atlas_size;
	FragColor = texture(atlas, final_UV);
}