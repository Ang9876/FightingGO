# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sept-lambda/Desktop/code/C++/CGpipeline

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CGpipeline.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CGpipeline.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CGpipeline.dir/flags.make

CMakeFiles/CGpipeline.dir/main.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CGpipeline.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/main.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/main.cpp

CMakeFiles/CGpipeline.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/main.cpp > CMakeFiles/CGpipeline.dir/main.cpp.i

CMakeFiles/CGpipeline.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/main.cpp -o CMakeFiles/CGpipeline.dir/main.cpp.s

CMakeFiles/CGpipeline.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/main.cpp.o.requires

CMakeFiles/CGpipeline.dir/main.cpp.o.provides: CMakeFiles/CGpipeline.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/main.cpp.o.provides

CMakeFiles/CGpipeline.dir/main.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/main.cpp.o


CMakeFiles/CGpipeline.dir/glad.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/glad.cpp.o: ../glad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CGpipeline.dir/glad.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/glad.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/glad.cpp

CMakeFiles/CGpipeline.dir/glad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/glad.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/glad.cpp > CMakeFiles/CGpipeline.dir/glad.cpp.i

CMakeFiles/CGpipeline.dir/glad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/glad.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/glad.cpp -o CMakeFiles/CGpipeline.dir/glad.cpp.s

CMakeFiles/CGpipeline.dir/glad.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/glad.cpp.o.requires

CMakeFiles/CGpipeline.dir/glad.cpp.o.provides: CMakeFiles/CGpipeline.dir/glad.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/glad.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/glad.cpp.o.provides

CMakeFiles/CGpipeline.dir/glad.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/glad.cpp.o


CMakeFiles/CGpipeline.dir/Shader.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/Shader.cpp.o: ../Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CGpipeline.dir/Shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/Shader.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/Shader.cpp

CMakeFiles/CGpipeline.dir/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/Shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/Shader.cpp > CMakeFiles/CGpipeline.dir/Shader.cpp.i

CMakeFiles/CGpipeline.dir/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/Shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/Shader.cpp -o CMakeFiles/CGpipeline.dir/Shader.cpp.s

CMakeFiles/CGpipeline.dir/Shader.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/Shader.cpp.o.requires

CMakeFiles/CGpipeline.dir/Shader.cpp.o.provides: CMakeFiles/CGpipeline.dir/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/Shader.cpp.o.provides

CMakeFiles/CGpipeline.dir/Shader.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/Shader.cpp.o


CMakeFiles/CGpipeline.dir/stb_image.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/stb_image.cpp.o: ../stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CGpipeline.dir/stb_image.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/stb_image.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/stb_image.cpp

CMakeFiles/CGpipeline.dir/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/stb_image.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/stb_image.cpp > CMakeFiles/CGpipeline.dir/stb_image.cpp.i

CMakeFiles/CGpipeline.dir/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/stb_image.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/stb_image.cpp -o CMakeFiles/CGpipeline.dir/stb_image.cpp.s

CMakeFiles/CGpipeline.dir/stb_image.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/stb_image.cpp.o.requires

CMakeFiles/CGpipeline.dir/stb_image.cpp.o.provides: CMakeFiles/CGpipeline.dir/stb_image.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/stb_image.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/stb_image.cpp.o.provides

CMakeFiles/CGpipeline.dir/stb_image.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/stb_image.cpp.o


CMakeFiles/CGpipeline.dir/Monster.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/Monster.cpp.o: ../Monster.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CGpipeline.dir/Monster.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/Monster.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/Monster.cpp

CMakeFiles/CGpipeline.dir/Monster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/Monster.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/Monster.cpp > CMakeFiles/CGpipeline.dir/Monster.cpp.i

CMakeFiles/CGpipeline.dir/Monster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/Monster.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/Monster.cpp -o CMakeFiles/CGpipeline.dir/Monster.cpp.s

CMakeFiles/CGpipeline.dir/Monster.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/Monster.cpp.o.requires

CMakeFiles/CGpipeline.dir/Monster.cpp.o.provides: CMakeFiles/CGpipeline.dir/Monster.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/Monster.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/Monster.cpp.o.provides

CMakeFiles/CGpipeline.dir/Monster.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/Monster.cpp.o


CMakeFiles/CGpipeline.dir/Model.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/Model.cpp.o: ../Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CGpipeline.dir/Model.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/Model.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/Model.cpp

CMakeFiles/CGpipeline.dir/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/Model.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/Model.cpp > CMakeFiles/CGpipeline.dir/Model.cpp.i

CMakeFiles/CGpipeline.dir/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/Model.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/Model.cpp -o CMakeFiles/CGpipeline.dir/Model.cpp.s

CMakeFiles/CGpipeline.dir/Model.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/Model.cpp.o.requires

CMakeFiles/CGpipeline.dir/Model.cpp.o.provides: CMakeFiles/CGpipeline.dir/Model.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/Model.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/Model.cpp.o.provides

CMakeFiles/CGpipeline.dir/Model.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/Model.cpp.o


CMakeFiles/CGpipeline.dir/Tree.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/Tree.cpp.o: ../Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CGpipeline.dir/Tree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/Tree.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/Tree.cpp

CMakeFiles/CGpipeline.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/Tree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/Tree.cpp > CMakeFiles/CGpipeline.dir/Tree.cpp.i

CMakeFiles/CGpipeline.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/Tree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/Tree.cpp -o CMakeFiles/CGpipeline.dir/Tree.cpp.s

CMakeFiles/CGpipeline.dir/Tree.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/Tree.cpp.o.requires

CMakeFiles/CGpipeline.dir/Tree.cpp.o.provides: CMakeFiles/CGpipeline.dir/Tree.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/Tree.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/Tree.cpp.o.provides

CMakeFiles/CGpipeline.dir/Tree.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/Tree.cpp.o


CMakeFiles/CGpipeline.dir/surface.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/surface.cpp.o: ../surface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CGpipeline.dir/surface.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/surface.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/surface.cpp

CMakeFiles/CGpipeline.dir/surface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/surface.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/surface.cpp > CMakeFiles/CGpipeline.dir/surface.cpp.i

CMakeFiles/CGpipeline.dir/surface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/surface.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/surface.cpp -o CMakeFiles/CGpipeline.dir/surface.cpp.s

CMakeFiles/CGpipeline.dir/surface.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/surface.cpp.o.requires

CMakeFiles/CGpipeline.dir/surface.cpp.o.provides: CMakeFiles/CGpipeline.dir/surface.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/surface.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/surface.cpp.o.provides

CMakeFiles/CGpipeline.dir/surface.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/surface.cpp.o


CMakeFiles/CGpipeline.dir/Gun.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/Gun.cpp.o: ../Gun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CGpipeline.dir/Gun.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/Gun.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/Gun.cpp

CMakeFiles/CGpipeline.dir/Gun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/Gun.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/Gun.cpp > CMakeFiles/CGpipeline.dir/Gun.cpp.i

CMakeFiles/CGpipeline.dir/Gun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/Gun.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/Gun.cpp -o CMakeFiles/CGpipeline.dir/Gun.cpp.s

CMakeFiles/CGpipeline.dir/Gun.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/Gun.cpp.o.requires

CMakeFiles/CGpipeline.dir/Gun.cpp.o.provides: CMakeFiles/CGpipeline.dir/Gun.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/Gun.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/Gun.cpp.o.provides

CMakeFiles/CGpipeline.dir/Gun.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/Gun.cpp.o


CMakeFiles/CGpipeline.dir/ifCollision.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/ifCollision.cpp.o: ../ifCollision.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/CGpipeline.dir/ifCollision.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/ifCollision.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/ifCollision.cpp

CMakeFiles/CGpipeline.dir/ifCollision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/ifCollision.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/ifCollision.cpp > CMakeFiles/CGpipeline.dir/ifCollision.cpp.i

CMakeFiles/CGpipeline.dir/ifCollision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/ifCollision.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/ifCollision.cpp -o CMakeFiles/CGpipeline.dir/ifCollision.cpp.s

CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.requires

CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.provides: CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.provides

CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/ifCollision.cpp.o


CMakeFiles/CGpipeline.dir/Skybox.cpp.o: CMakeFiles/CGpipeline.dir/flags.make
CMakeFiles/CGpipeline.dir/Skybox.cpp.o: ../Skybox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/CGpipeline.dir/Skybox.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGpipeline.dir/Skybox.cpp.o -c /Users/sept-lambda/Desktop/code/C++/CGpipeline/Skybox.cpp

CMakeFiles/CGpipeline.dir/Skybox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGpipeline.dir/Skybox.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sept-lambda/Desktop/code/C++/CGpipeline/Skybox.cpp > CMakeFiles/CGpipeline.dir/Skybox.cpp.i

CMakeFiles/CGpipeline.dir/Skybox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGpipeline.dir/Skybox.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sept-lambda/Desktop/code/C++/CGpipeline/Skybox.cpp -o CMakeFiles/CGpipeline.dir/Skybox.cpp.s

CMakeFiles/CGpipeline.dir/Skybox.cpp.o.requires:

.PHONY : CMakeFiles/CGpipeline.dir/Skybox.cpp.o.requires

CMakeFiles/CGpipeline.dir/Skybox.cpp.o.provides: CMakeFiles/CGpipeline.dir/Skybox.cpp.o.requires
	$(MAKE) -f CMakeFiles/CGpipeline.dir/build.make CMakeFiles/CGpipeline.dir/Skybox.cpp.o.provides.build
.PHONY : CMakeFiles/CGpipeline.dir/Skybox.cpp.o.provides

CMakeFiles/CGpipeline.dir/Skybox.cpp.o.provides.build: CMakeFiles/CGpipeline.dir/Skybox.cpp.o


# Object files for target CGpipeline
CGpipeline_OBJECTS = \
"CMakeFiles/CGpipeline.dir/main.cpp.o" \
"CMakeFiles/CGpipeline.dir/glad.cpp.o" \
"CMakeFiles/CGpipeline.dir/Shader.cpp.o" \
"CMakeFiles/CGpipeline.dir/stb_image.cpp.o" \
"CMakeFiles/CGpipeline.dir/Monster.cpp.o" \
"CMakeFiles/CGpipeline.dir/Model.cpp.o" \
"CMakeFiles/CGpipeline.dir/Tree.cpp.o" \
"CMakeFiles/CGpipeline.dir/surface.cpp.o" \
"CMakeFiles/CGpipeline.dir/Gun.cpp.o" \
"CMakeFiles/CGpipeline.dir/ifCollision.cpp.o" \
"CMakeFiles/CGpipeline.dir/Skybox.cpp.o"

# External object files for target CGpipeline
CGpipeline_EXTERNAL_OBJECTS =

CGpipeline: CMakeFiles/CGpipeline.dir/main.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/glad.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/Shader.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/stb_image.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/Monster.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/Model.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/Tree.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/surface.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/Gun.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/ifCollision.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/Skybox.cpp.o
CGpipeline: CMakeFiles/CGpipeline.dir/build.make
CGpipeline: CMakeFiles/CGpipeline.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable CGpipeline"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CGpipeline.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CGpipeline.dir/build: CGpipeline

.PHONY : CMakeFiles/CGpipeline.dir/build

CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/main.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/glad.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/Shader.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/stb_image.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/Monster.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/Model.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/Tree.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/surface.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/Gun.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/ifCollision.cpp.o.requires
CMakeFiles/CGpipeline.dir/requires: CMakeFiles/CGpipeline.dir/Skybox.cpp.o.requires

.PHONY : CMakeFiles/CGpipeline.dir/requires

CMakeFiles/CGpipeline.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CGpipeline.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CGpipeline.dir/clean

CMakeFiles/CGpipeline.dir/depend:
	cd /Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sept-lambda/Desktop/code/C++/CGpipeline /Users/sept-lambda/Desktop/code/C++/CGpipeline /Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug /Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug /Users/sept-lambda/Desktop/code/C++/CGpipeline/cmake-build-debug/CMakeFiles/CGpipeline.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CGpipeline.dir/depend

