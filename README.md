# MyRPGEngine
My try to make 2D RPG Game Engine inspired by RPG Maker although smaller and open.

## How to build

#### Cmake
```bash
# Clone the repository and enter the directory
git clone https://github.com/Moztanku/MyRPGEngine.git
cd MyRPGEngine

# Create build files and build the project
cmake -S . -B build
cmake --build build

# Run the engine (not doing very much yet)
./build/MyRPGEngine
```

## Requirements
- [OpenGL](https://opengl.org/ "OpenGL's website")
- [GLFW](https://glfw.org/ "GLFW's website")
- [GLM](https://github.com/g-truc/glm/ "GLM's repository")

### TODO (In random order)
- Integrate Entity-Component-System
- - NPCs
- - Player
- - AI
- - Items
- - Dialogue trees
- - Quests
- - Inventory
- - Stats
- - Combat
- Rendering
- - Tilemap with layers
- - Sprites with animations
- - Text
- - Particles
- - GUI
- - Custom shaders support
- - (Maybe) Lighting
- - (Maybe) Add 2.5D mode
- Audio
- - SFX
- - BGM
- Physics
- - Collision detection
- - Trigger zones
- Event Handling
- - ~~Integrate with ECS~~
- - ~~Keyboard & Mouse input~~
- - ~~Window events~~
- - Timers
- - (Maybe) Gamepad input
- - (Maybe) Networking
- Implement Lua scripting
- - Integrate with ECS
- - Implement API
- Visual Editor
- - Tilemap editor
- - Collision editor
- - NPC editor
- - Dialogue editor
- - Script editor
- - Etc.