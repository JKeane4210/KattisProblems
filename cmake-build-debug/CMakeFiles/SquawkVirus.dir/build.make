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
include CMakeFiles/SquawkVirus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SquawkVirus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SquawkVirus.dir/flags.make

CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.o: CMakeFiles/SquawkVirus.dir/flags.make
CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.o: ../MSOE2021Summer/Week6/SquawkVirus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.o -c /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week6/SquawkVirus.cpp

CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week6/SquawkVirus.cpp > CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.i

CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jkeane/CLionProjects/KattisProblems/MSOE2021Summer/Week6/SquawkVirus.cpp -o CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.s

# Object files for target SquawkVirus
SquawkVirus_OBJECTS = \
"CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.o"

# External object files for target SquawkVirus
SquawkVirus_EXTERNAL_OBJECTS =

SquawkVirus: CMakeFiles/SquawkVirus.dir/MSOE2021Summer/Week6/SquawkVirus.cpp.o
SquawkVirus: CMakeFiles/SquawkVirus.dir/build.make
SquawkVirus: CMakeFiles/SquawkVirus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SquawkVirus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SquawkVirus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SquawkVirus.dir/build: SquawkVirus

.PHONY : CMakeFiles/SquawkVirus.dir/build

CMakeFiles/SquawkVirus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SquawkVirus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SquawkVirus.dir/clean

CMakeFiles/SquawkVirus.dir/depend:
	cd /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug /Users/jkeane/CLionProjects/KattisProblems/cmake-build-debug/CMakeFiles/SquawkVirus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SquawkVirus.dir/depend

