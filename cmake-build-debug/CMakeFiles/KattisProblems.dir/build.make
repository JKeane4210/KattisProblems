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
include CMakeFiles/KattisProblems.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KattisProblems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KattisProblems.dir/flags.make

CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.o: CMakeFiles/KattisProblems.dir/flags.make
CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.o: ../singleSourceNegativeWeights.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.o -c /Users/jkeane/CLionProjects/KattisProblems/singleSourceNegativeWeights.cpp

CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/KattisProblems/singleSourceNegativeWeights.cpp > CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.i

CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/KattisProblems/singleSourceNegativeWeights.cpp -o CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.s

# Object files for target KattisProblems
KattisProblems_OBJECTS = \
"CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.o"

# External object files for target KattisProblems
KattisProblems_EXTERNAL_OBJECTS =

KattisProblems: CMakeFiles/KattisProblems.dir/singleSourceNegativeWeights.cpp.o
KattisProblems: CMakeFiles/KattisProblems.dir/build.make
KattisProblems: CMakeFiles/KattisProblems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KattisProblems"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KattisProblems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KattisProblems.dir/build: KattisProblems

.PHONY : CMakeFiles/KattisProblems.dir/build

CMakeFiles/KattisProblems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KattisProblems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KattisProblems.dir/clean

CMakeFiles/KattisProblems.dir/depend:
	cd /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles/KattisProblems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KattisProblems.dir/depend

