#version 460 core

out vec4 FragColor;

in vec2 UV;
uniform sampler2D atlas;
uniform usampler2D tiles;
uniform sampler2D blend_mask;
uniform uvec2 atlas_size;
uniform uvec2 grid_size;

vec2 getTilePos(uint tile) {
	return vec2(tile%atlas_size.x, atlas_size.y-1-tile/atlas_size.x) / atlas_size;
}

void main() {
	uint tile = texture(tiles, UV).r;
	vec2 tile_pos = getTilePos(tile);
	vec2 tile_size = vec2(1/float(grid_size.x), 1/float(grid_size.y));
	vec2 tile_UV = vec2(mod(UV.x,tile_size.x), mod(UV.y,tile_size.y)) * grid_size;
	vec2 final_UV = tile_pos + tile_UV / atlas_size;

	FragColor = texture(atlas, final_UV);

	uint tile_above = texture(tiles, UV+vec2(0, tile_size.y)).r;
	uint tile_below = texture(tiles, UV-vec2(0, tile_size.y)).r;
	uint tile_right = texture(tiles, UV+vec2(tile_size.x, 0)).r;
	uint tile_left  = texture(tiles, UV-vec2(tile_size.x, 0)).r;

	if (tile != tile_above) {
		vec3 mask_color = texture(blend_mask, tile_UV).rgb;
		float mask = (mask_color.r + mask_color.g + mask_color.b) / 3.;

		vec2 neighbour_tile_UV = getTilePos(tile_above) + tile_UV/atlas_size;
		FragColor = mix(FragColor, texture(atlas, neighbour_tile_UV), mask);
	}
	if (tile != tile_below) {
		vec3 mask_color = texture(blend_mask, vec2(1, 1)-tile_UV).rgb;
		float mask = (mask_color.r + mask_color.g + mask_color.b) / 3.;

		vec2 neighbour_tile_UV = getTilePos(tile_below) + tile_UV/atlas_size;
		FragColor = mix(FragColor, texture(atlas, neighbour_tile_UV), mask);
	}
	if (tile != tile_right) {
		vec3 mask_color = texture(blend_mask, tile_UV.yx).rgb;
		float mask = (mask_color.r + mask_color.g + mask_color.b) / 3.;

		vec2 neighbour_tile_UV = getTilePos(tile_right) + tile_UV/atlas_size;
		FragColor = mix(FragColor, texture(atlas, neighbour_tile_UV), mask);
	}
	if (tile != tile_left) {
		vec3 mask_color = texture(blend_mask, vec2(1, 1)-tile_UV.yx).rgb;
		float mask = (mask_color.r + mask_color.g + mask_color.b) / 3.;

		vec2 neighbour_tile_UV = getTilePos(tile_left) + tile_UV/atlas_size;
		FragColor = mix(FragColor, texture(atlas, neighbour_tile_UV), mask);
	}
}