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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jkeane/CLionProjects/KattisProblems

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MultiplicationGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MultiplicationGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MultiplicationGame.dir/flags.make

CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.o: CMakeFiles/MultiplicationGame.dir/flags.make
CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.o: ../MSOE2021Summer/Week4/MultiplicationGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.o -c /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week4/MultiplicationGame.cpp

CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week4/MultiplicationGame.cpp > CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.i

CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week4/MultiplicationGame.cpp -o CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.s

# Object files for target MultiplicationGame
MultiplicationGame_OBJECTS = \
"CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.o"

# External object files for target MultiplicationGame
MultiplicationGame_EXTERNAL_OBJECTS =

MultiplicationGame: CMakeFiles/MultiplicationGame.dir/MSOE2021Summer/Week4/MultiplicationGame.cpp.o
MultiplicationGame: CMakeFiles/MultiplicationGame.dir/build.make
MultiplicationGame: CMakeFiles/MultiplicationGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MultiplicationGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MultiplicationGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MultiplicationGame.dir/build: MultiplicationGame

.PHONY : CMakeFiles/MultiplicationGame.dir/build

CMakeFiles/MultiplicationGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MultiplicationGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MultiplicationGame.dir/clean

CMakeFiles/MultiplicationGame.dir/depend:
	cd /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles/MultiplicationGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MultiplicationGame.dir/depend
