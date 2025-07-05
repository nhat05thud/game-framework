# Game Framework
A simple game engine written in C++, inspired by [Son of Spades](https://sonofspades.com/).

## ✨ Features
- **C++**: Core game engine.

## 🚀 How to Build & Run

### Prerequisites

- [CMake](https://cmake.org/)
- IDE:
    - [CLion](https://www.jetbrains.com/clion/) (Cross-platform) — *Recommended*
    - [Visual Studio](https://visualstudio.microsoft.com/) (Windows)

```bash
git clone --recursive https://github.com/nhat05thud/game-framework.git
```

### Configuration

#### ⏺ CLion Settings:

- Go to: ```Settings``` → ```Build, Execution, Deployment``` → ```CMake```
    - Generator: ```Visual Studio 17 2022```
    - CMake options:
      ```bash
      -G "Visual Studio 17 2022"
      -DCMAKE_RUNTIME_OUTPUT_DIRECTORY:PATH=$CMakeProjectDir$/build
      -DCMAKE_CXX_STANDARD_REQUIRED:BOOL=ON
      -DCMAKE_CXX_STANDARD:STRING=23
      ```
    - Build directory: ```cmake/debug```
    - Cache variables: ```DGLFW_BUILD_EXAMPLES → ON``` ```DGLFW_BUILD_TESTS → ON```

#### ⏺ Visual Studio Settings:

- Edit ```CMakeSettings.json:```
```json
{
  "configurations": [
    {
      "name": "x64-Debug",
      "generator": "Visual Studio 17 2022 Win64",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x64_x64" ],
      "buildRoot": "${projectDir}\\cmake\\build\\${name}",
      "installRoot": "${projectDir}\\cmake\\install\\${name}",
      "cmakeCommandArgs": "",
      "variables": [
        {
          "name": "CMAKE_CXX_STANDARD",
          "value": "23"
        },
        {
          "name": "CMAKE_CXX_STANDARD_REQUIRED",
          "value": "ON"
        },
        {
          "name": "CMAKE_RUNTIME_OUTPUT_DIRECTORY",
          "value": "${projectDir}\\build"
        },
        {
          "name": "GLFW_BUILD_EXAMPLES",
          "value": "ON"
        },
        {
          "name": "GLFW_BUILD_TESTS",
          "value": "ON"
        }
      ]
    }
  ]
}
```