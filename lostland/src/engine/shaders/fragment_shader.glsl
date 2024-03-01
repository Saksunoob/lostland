#version 460 core

out vec4 FragColor;

in vec2 UV;
uniform sampler2D texture_image;

void main() {
	vec4 texColor = texture(texture_image, UV);
	if (texColor.a <= 0.5)
		discard;
	FragColor = texColor;
}