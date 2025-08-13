# cub3d

## Overview
cub3d is a 3D game engine inspired by the classic Wolfenstein 3D. This project implements raycasting technology to create a pseudo-3D environment with textured walls, sprites, and interactive gameplay. It demonstrates advanced graphics programming, game engine architecture, and real-time rendering.

## Features
- **3D Raycasting Engine**: Creates pseudo-3D environments using raycasting
- **Textured Walls**: Multiple texture support for walls and surfaces
- **Interactive Controls**: WASD movement, mouse look, and collision detection
- **Map System**: Custom map format with wall placement and textures
- **Sprite Rendering**: Support for 2D sprites in 3D space
- **Real-time Rendering**: Smooth 60 FPS gameplay
- **Sound Support**: Audio integration for immersive experience

## How It Works
1. **Raycasting**: Casts rays from player position to determine wall distances
2. **Texture Mapping**: Applies textures to walls based on ray intersections
3. **Player Movement**: Handles input and collision detection
4. **Rendering Pipeline**: Draws walls, floors, ceilings, and sprites
5. **Game Loop**: Continuous update and render cycle

## Project Structure
```
cub3d/
├── cub3d.h                  # Main header with structures and declarations
├── cub3d.c                  # Main program entry point
├── init.c                   # Game initialization functions
├── raycast.c                # Core raycasting algorithm
├── ray_calculation.c        # Ray mathematics and calculations
├── draw_wall.c              # Wall rendering functions
├── textures.c               # Texture loading and management
├── key.c                    # Input handling and key events
├── key_moves.c              # Player movement logic
├── key_rotation.c           # Camera rotation handling
├── parse_map.c              # Map file parsing
├── check_map.c              # Map validation
├── check_map2.c             # Extended map validation
├── check_files.c            # File validation
├── map.c                    # Map data structures
├── map_utils.c              # Map utility functions
├── utils.c                  # General utility functions
├── utils2.c                 # Extended utility functions
├── utils_draw.c             # Drawing utility functions
├── raycast_help.c           # Raycasting helper functions
├── Makefile                 # Build configuration
├── *.cub                    # Map configuration files
├── *.xpm                    # Texture files
└── .git/                   # Git repository
```

## Map Format (.cub)
The .cub files define the game world:
- **Map Layout**: 2D grid representing walls and spaces
- **Textures**: Paths to texture files for walls
- **Colors**: RGB values for floor and ceiling
- **Player Position**: Starting coordinates and orientation
- **Sprites**: Object placements and properties

## Controls
- **WASD**: Move forward, backward, left, right
- **Mouse**: Look around (camera rotation)
- **Arrow Keys**: Alternative movement controls
- **ESC**: Exit the game
- **M**: Toggle minimap (if implemented)

## Usage
```bash
# Compile the game
make

# Run with a map file
./cub3d maps/example.cub

# Clean build files
make clean
```



## Requirements
- GCC compiler
- Make utility
- Standard C libraries
- MLX graphics library
- Libft library (dependency)

## Dependencies
This project depends on:
- Libft library for basic functions
- MLX library for graphics, window management, and input handling

## Graphics Features
- **Raycasting Engine**: Efficient pseudo-3D rendering
- **Texture Mapping**: High-quality wall textures
- **Dynamic Lighting**: Distance-based lighting effects
- **Smooth Movement**: Fluid player and camera movement
- **Collision Detection**: Realistic wall and object interaction

## Performance Features
- **Optimized Rendering**: Efficient raycasting algorithms
- **Memory Management**: Smart texture and asset loading
- **Frame Rate Control**: Consistent 60 FPS gameplay
- **Resource Optimization**: Minimal memory footprint

## Notes
- Follows 42 coding style (norminette)
- Implements complex 3D graphics algorithms
- Handles various map and texture formats
- Memory-safe implementation
- Optimized for real-time gaming performance

## Author
shmohamm - 42 Abu Dhabi
