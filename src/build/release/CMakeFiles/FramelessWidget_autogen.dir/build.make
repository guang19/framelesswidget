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
CMAKE_SOURCE_DIR = /home/guang19/MyProject/framelesswidget/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guang19/MyProject/framelesswidget/src/build/release

# Utility rule file for FramelessWidget_autogen.

# Include the progress variables for this target.
include CMakeFiles/FramelessWidget_autogen.dir/progress.make

CMakeFiles/FramelessWidget_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guang19/MyProject/framelesswidget/src/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target FramelessWidget"
	/home/guang19/Application/clion-2021.1.3/bin/cmake/linux/bin/cmake -E cmake_autogen /home/guang19/MyProject/framelesswidget/src/build/release/CMakeFiles/FramelessWidget_autogen.dir/AutogenInfo.json Release

FramelessWidget_autogen: CMakeFiles/FramelessWidget_autogen
FramelessWidget_autogen: CMakeFiles/FramelessWidget_autogen.dir/build.make

.PHONY : FramelessWidget_autogen

# Rule to build all files generated by this target.
CMakeFiles/FramelessWidget_autogen.dir/build: FramelessWidget_autogen

.PHONY : CMakeFiles/FramelessWidget_autogen.dir/build

CMakeFiles/FramelessWidget_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FramelessWidget_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FramelessWidget_autogen.dir/clean

CMakeFiles/FramelessWidget_autogen.dir/depend:
	cd /home/guang19/MyProject/framelesswidget/src/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guang19/MyProject/framelesswidget/src /home/guang19/MyProject/framelesswidget/src /home/guang19/MyProject/framelesswidget/src/build/release /home/guang19/MyProject/framelesswidget/src/build/release /home/guang19/MyProject/framelesswidget/src/build/release/CMakeFiles/FramelessWidget_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FramelessWidget_autogen.dir/depend

