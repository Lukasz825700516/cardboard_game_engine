# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lukasz/projects/cardboard_game_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lukasz/projects/cardboard_game_engine/build

# Include any dependencies generated for this target.
include CMakeFiles/cardboard_game_engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cardboard_game_engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cardboard_game_engine.dir/flags.make

CMakeFiles/cardboard_game_engine.dir/src/main.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/main.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/main.cpp

CMakeFiles/cardboard_game_engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/main.cpp > CMakeFiles/cardboard_game_engine.dir/src/main.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/main.cpp -o CMakeFiles/cardboard_game_engine.dir/src/main.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.o: ../src/resources/file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/resources/file.cpp

CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/resources/file.cpp > CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/resources/file.cpp -o CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.o: ../src/graphics/vertex_buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex_buffer.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex_buffer.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex_buffer.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.o: ../src/graphics/vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.o: ../src/graphics/element_buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/element_buffer.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/element_buffer.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/element_buffer.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.o: ../src/graphics/context.opengl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/context.opengl.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/context.opengl.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/context.opengl.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.o: ../src/graphics/shader.opengl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/shader.opengl.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/shader.opengl.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/shader.opengl.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.o: ../src/graphics/vertex_buffer.opengl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex_buffer.opengl.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex_buffer.opengl.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/vertex_buffer.opengl.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.o: ../src/graphics/element_buffer.opengl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/element_buffer.opengl.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/element_buffer.opengl.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/element_buffer.opengl.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.s

CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.o: CMakeFiles/cardboard_game_engine.dir/flags.make
CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.o: ../src/graphics/window.opengl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.o -c /home/lukasz/projects/cardboard_game_engine/src/graphics/window.opengl.cpp

CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/projects/cardboard_game_engine/src/graphics/window.opengl.cpp > CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.i

CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/projects/cardboard_game_engine/src/graphics/window.opengl.cpp -o CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.s

# Object files for target cardboard_game_engine
cardboard_game_engine_OBJECTS = \
"CMakeFiles/cardboard_game_engine.dir/src/main.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.o" \
"CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.o"

# External object files for target cardboard_game_engine
cardboard_game_engine_EXTERNAL_OBJECTS =

cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/main.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/resources/file.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/context.opengl.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/shader.opengl.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/vertex_buffer.opengl.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/element_buffer.opengl.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/src/graphics/window.opengl.cpp.o
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/build.make
cardboard_game_engine: /usr/lib/libglfw.so.3.3
cardboard_game_engine: dep/glad/libglad.so
cardboard_game_engine: /usr/lib/libGLX.so
cardboard_game_engine: /usr/lib/libOpenGL.so
cardboard_game_engine: CMakeFiles/cardboard_game_engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lukasz/projects/cardboard_game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable cardboard_game_engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cardboard_game_engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cardboard_game_engine.dir/build: cardboard_game_engine

.PHONY : CMakeFiles/cardboard_game_engine.dir/build

CMakeFiles/cardboard_game_engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cardboard_game_engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cardboard_game_engine.dir/clean

CMakeFiles/cardboard_game_engine.dir/depend:
	cd /home/lukasz/projects/cardboard_game_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lukasz/projects/cardboard_game_engine /home/lukasz/projects/cardboard_game_engine /home/lukasz/projects/cardboard_game_engine/build /home/lukasz/projects/cardboard_game_engine/build /home/lukasz/projects/cardboard_game_engine/build/CMakeFiles/cardboard_game_engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cardboard_game_engine.dir/depend

