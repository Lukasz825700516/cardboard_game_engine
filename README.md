# Cardboard Game Engine

## How to compile

You have to have installed cmake!

Clone an cd into repo
```
git clone https://github.com/Lukasz825700516/cardboard_game_engine.git
cd cardboard_game_engine
```

Create build directory, and cd into it
```
mkdir build
cd build
```

Create project using cmake
Project will in future support multiple rendering targets, so you need to specify one
```
cmake .. -DCARDBOARD_GRAPHICS_TARGET=opengl -DCARDBOARD_WINDOWS_TARGET=glfw
```

And then build it, with thing that cmake has generated for you
On *nix it will probably be make, on windows VisualStudio I guess...
```
make cardboard_game_engine
```
