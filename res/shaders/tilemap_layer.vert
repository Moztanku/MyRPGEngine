#version 460 core

// Tile position starting from layers origin.
layout (location = 0) in vec2 aPos;

// Tile position within tileset texture, 0 would be the first tile, 1 the second etc.
layout (location = 1) in uint aTexPos;

out vec2 texCoord;

// Origin point of the tilemap layer, where (0,0) pos starts
uniform vec2 uOrigin = vec2(0.0, 0.0);
// Z index used to know what should be draw on top of what
uniform float uZIndex = 1.0;

// Model, View, Projection matrix
uniform mat4 uModel = mat4(1.0);
uniform mat4 uProjectionView = mat4(1.0);

// Texture size
uniform uvec2 uTexDimensions = uvec2(512,512);
// Size of a singular tile within texture
uniform uvec2 uTileSize = uvec2(32,32);

void main()
{
    uint tex_temp = aTexPos * uTileSize.x;

    uint tex_x = tex_temp % uTexDimensions.x;
    uint tex_y = (tex_temp / uTexDimensions.y) * uTileSize.y;

    texCoord = vec2(float(tex_x), float(tex_y)) + mod(aPos, uTileSize);

    gl_Position = uProjectionView * uModel * vec4(aPos + uOrigin, uZIndex, 1.0);
}
