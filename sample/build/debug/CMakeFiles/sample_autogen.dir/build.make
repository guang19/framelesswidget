# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/guang19/Application/clion-2021.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/guang19/Application/clion-2021.1.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guang19/MyProject/framelesswidget/sample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guang19/MyProject/framelesswidget/sample/build/debug

# Utility rule file for sample_autogen.

# Include the progress variables for this target.
include CMakeFiles/sample_autogen.dir/progress.make

CMakeFiles/sample_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guang19/MyProject/framelesswidget/sample/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target sample"
	/home/guang19/Application/clion-2021.1.3/bin/cmake/linux/bin/cmake -E cmake_autogen /home/guang19/MyProject/framelesswidget/sample/build/debug/CMakeFiles/sample_autogen.dir/AutogenInfo.json Debug

sample_autogen: CMakeFiles/sample_autogen
sample_autogen: CMakeFiles/sample_autogen.dir/build.make

.PHONY : sample_autogen

# Rule to build all files generated by this target.
CMakeFiles/sample_autogen.dir/build: sample_autogen

.PHONY : CMakeFiles/sample_autogen.dir/build

CMakeFiles/sample_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample_autogen.dir/clean

CMakeFiles/sample_autogen.dir/depend:
	cd /home/guang19/MyProject/framelesswidget/sample/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guang19/MyProject/framelesswidget/sample /home/guang19/MyProject/framelesswidget/sample /home/guang19/MyProject/framelesswidget/sample/build/debug /home/guang19/MyProject/framelesswidget/sample/build/debug /home/guang19/MyProject/framelesswidget/sample/build/debug/CMakeFiles/sample_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample_autogen.dir/depend

