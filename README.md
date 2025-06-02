
> Note: The project integrates raylib directly into its structure and provides multiple `.vcxproj` files for building various examples and scenes.

![alt text](Sim-2.png)

## 🧩 Features

- Real-time 2D and/or 3D physics-based interactions
- Integration with raylib for rendering and input
- Visual Studio 2022 compatibility
- Multiple example scenes and camera systems
- Extensible game loop and physics engine

## 🚀 Getting Started

### Prerequisites

- Windows with Visual Studio 2022
- CMake (optional)
- C/C++ build tools installed
- Git (optional for source control)

### Build Instructions (Visual Studio)

1. Open the `.sln` file or any of the `.vcxproj` files located in `projects/VS2022/`.
2. Build the solution.
3. Run the executable from Visual Studio or via command line.

### Alternative Build (Using Make)

Navigate to the raylib `projects/VSCode` folder:

```bash
cd Physics/build/external/raylib-master/projects/VSCode
make
