#version 460 core

out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D uTilesetTexture;

void main()
{
    FragColor = texture(uTilesetTexture, texCoord);
}
