# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/duncanforbes/Documents/dealii-workspace/short-crack-model

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build

# Include any dependencies generated for this target.
include CMakeFiles/short-crack-model.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/short-crack-model.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/short-crack-model.dir/flags.make

CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.o: CMakeFiles/short-crack-model.dir/flags.make
CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.o: ../src/BoundaryValues.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.o -c /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/BoundaryValues.cc

CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/BoundaryValues.cc > CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.i

CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/BoundaryValues.cc -o CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.s

CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.o: CMakeFiles/short-crack-model.dir/flags.make
CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.o: ../src/RightHandSide.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.o -c /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/RightHandSide.cc

CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/RightHandSide.cc > CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.i

CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/RightHandSide.cc -o CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.s

CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.o: CMakeFiles/short-crack-model.dir/flags.make
CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.o: ../src/ShortCrack.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.o -c /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/ShortCrack.cc

CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/ShortCrack.cc > CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.i

CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/ShortCrack.cc -o CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.s

CMakeFiles/short-crack-model.dir/src/main.cc.o: CMakeFiles/short-crack-model.dir/flags.make
CMakeFiles/short-crack-model.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/short-crack-model.dir/src/main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/short-crack-model.dir/src/main.cc.o -c /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/main.cc

CMakeFiles/short-crack-model.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/short-crack-model.dir/src/main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/main.cc > CMakeFiles/short-crack-model.dir/src/main.cc.i

CMakeFiles/short-crack-model.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/short-crack-model.dir/src/main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/src/main.cc -o CMakeFiles/short-crack-model.dir/src/main.cc.s

# Object files for target short-crack-model
short__crack__model_OBJECTS = \
"CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.o" \
"CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.o" \
"CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.o" \
"CMakeFiles/short-crack-model.dir/src/main.cc.o"

# External object files for target short-crack-model
short__crack__model_EXTERNAL_OBJECTS =

short-crack-model: CMakeFiles/short-crack-model.dir/src/BoundaryValues.cc.o
short-crack-model: CMakeFiles/short-crack-model.dir/src/RightHandSide.cc.o
short-crack-model: CMakeFiles/short-crack-model.dir/src/ShortCrack.cc.o
short-crack-model: CMakeFiles/short-crack-model.dir/src/main.cc.o
short-crack-model: CMakeFiles/short-crack-model.dir/build.make
short-crack-model: /usr/local/lib/libdeal_II.g.9.0.0.dylib
short-crack-model: /usr/lib/libz.dylib
short-crack-model: CMakeFiles/short-crack-model.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable short-crack-model"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/short-crack-model.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/short-crack-model.dir/build: short-crack-model

.PHONY : CMakeFiles/short-crack-model.dir/build

CMakeFiles/short-crack-model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/short-crack-model.dir/cmake_clean.cmake
.PHONY : CMakeFiles/short-crack-model.dir/clean

CMakeFiles/short-crack-model.dir/depend:
	cd /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/duncanforbes/Documents/dealii-workspace/short-crack-model /Users/duncanforbes/Documents/dealii-workspace/short-crack-model /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build /Users/duncanforbes/Documents/dealii-workspace/short-crack-model/build/CMakeFiles/short-crack-model.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/short-crack-model.dir/depend

