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
include CMakeFiles/Difference.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Difference.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Difference.dir/flags.make

CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.o: CMakeFiles/Difference.dir/flags.make
CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.o: ../MSOE2021Summer/Week1/Difference.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.o -c /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week1/Difference.cpp

CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week1/Difference.cpp > CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.i

CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week1/Difference.cpp -o CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.s

# Object files for target Difference
Difference_OBJECTS = \
"CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.o"

# External object files for target Difference
Difference_EXTERNAL_OBJECTS =

Difference: CMakeFiles/Difference.dir/MSOE2021Summer/Week1/Difference.cpp.o
Difference: CMakeFiles/Difference.dir/build.make
Difference: CMakeFiles/Difference.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Difference"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Difference.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Difference.dir/build: Difference

.PHONY : CMakeFiles/Difference.dir/build

CMakeFiles/Difference.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Difference.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Difference.dir/clean

CMakeFiles/Difference.dir/depend:
	cd /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles/Difference.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Difference.dir/depend

