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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chocolate/Documents/Web_App_Dictionary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chocolate/Documents/Web_App_Dictionary/build

# Include any dependencies generated for this target.
include CMakeFiles/SuperDictionary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SuperDictionary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SuperDictionary.dir/flags.make

CMakeFiles/SuperDictionary.dir/dictionary.cpp.o: CMakeFiles/SuperDictionary.dir/flags.make
CMakeFiles/SuperDictionary.dir/dictionary.cpp.o: ../dictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chocolate/Documents/Web_App_Dictionary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SuperDictionary.dir/dictionary.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SuperDictionary.dir/dictionary.cpp.o -c /Users/chocolate/Documents/Web_App_Dictionary/dictionary.cpp

CMakeFiles/SuperDictionary.dir/dictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SuperDictionary.dir/dictionary.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chocolate/Documents/Web_App_Dictionary/dictionary.cpp > CMakeFiles/SuperDictionary.dir/dictionary.cpp.i

CMakeFiles/SuperDictionary.dir/dictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SuperDictionary.dir/dictionary.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chocolate/Documents/Web_App_Dictionary/dictionary.cpp -o CMakeFiles/SuperDictionary.dir/dictionary.cpp.s

# Object files for target SuperDictionary
SuperDictionary_OBJECTS = \
"CMakeFiles/SuperDictionary.dir/dictionary.cpp.o"

# External object files for target SuperDictionary
SuperDictionary_EXTERNAL_OBJECTS =

SuperDictionary: CMakeFiles/SuperDictionary.dir/dictionary.cpp.o
SuperDictionary: CMakeFiles/SuperDictionary.dir/build.make
SuperDictionary: libmongoose.a
SuperDictionary: CMakeFiles/SuperDictionary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chocolate/Documents/Web_App_Dictionary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SuperDictionary"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SuperDictionary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SuperDictionary.dir/build: SuperDictionary

.PHONY : CMakeFiles/SuperDictionary.dir/build

CMakeFiles/SuperDictionary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SuperDictionary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SuperDictionary.dir/clean

CMakeFiles/SuperDictionary.dir/depend:
	cd /Users/chocolate/Documents/Web_App_Dictionary/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chocolate/Documents/Web_App_Dictionary /Users/chocolate/Documents/Web_App_Dictionary /Users/chocolate/Documents/Web_App_Dictionary/build /Users/chocolate/Documents/Web_App_Dictionary/build /Users/chocolate/Documents/Web_App_Dictionary/build/CMakeFiles/SuperDictionary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SuperDictionary.dir/depend

