# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /vagrant/workspace/CM_FW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant/workspace/CM_FW/build

# Include any dependencies generated for this target.
include CommonLib/CMakeFiles/COMMONLIB.dir/depend.make

# Include the progress variables for this target.
include CommonLib/CMakeFiles/COMMONLIB.dir/progress.make

# Include the compile flags for this target's objects.
include CommonLib/CMakeFiles/COMMONLIB.dir/flags.make

CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o: CommonLib/CMakeFiles/COMMONLIB.dir/flags.make
CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o: ../CommonLib/src/Algrithm.c
	$(CMAKE_COMMAND) -E cmake_progress_report /vagrant/workspace/CM_FW/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o"
	cd /vagrant/workspace/CM_FW/build/CommonLib && /opt/fsl-networking/QorIQ-SDK-V1.7/sysroots/i686-fslsdk-linux/usr/bin/powerpc-fsl-linux-gnuspe/powerpc-fsl-linux-gnuspe-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o   -c /vagrant/workspace/CM_FW/CommonLib/src/Algrithm.c

CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/COMMONLIB.dir/src/Algrithm.c.i"
	cd /vagrant/workspace/CM_FW/build/CommonLib && /opt/fsl-networking/QorIQ-SDK-V1.7/sysroots/i686-fslsdk-linux/usr/bin/powerpc-fsl-linux-gnuspe/powerpc-fsl-linux-gnuspe-gcc  $(C_DEFINES) $(C_FLAGS) -E /vagrant/workspace/CM_FW/CommonLib/src/Algrithm.c > CMakeFiles/COMMONLIB.dir/src/Algrithm.c.i

CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/COMMONLIB.dir/src/Algrithm.c.s"
	cd /vagrant/workspace/CM_FW/build/CommonLib && /opt/fsl-networking/QorIQ-SDK-V1.7/sysroots/i686-fslsdk-linux/usr/bin/powerpc-fsl-linux-gnuspe/powerpc-fsl-linux-gnuspe-gcc  $(C_DEFINES) $(C_FLAGS) -S /vagrant/workspace/CM_FW/CommonLib/src/Algrithm.c -o CMakeFiles/COMMONLIB.dir/src/Algrithm.c.s

CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.requires:
.PHONY : CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.requires

CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.provides: CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.requires
	$(MAKE) -f CommonLib/CMakeFiles/COMMONLIB.dir/build.make CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.provides.build
.PHONY : CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.provides

CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.provides.build: CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o

# Object files for target COMMONLIB
COMMONLIB_OBJECTS = \
"CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o"

# External object files for target COMMONLIB
COMMONLIB_EXTERNAL_OBJECTS =

CommonLib/libCOMMONLIB.a: CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o
CommonLib/libCOMMONLIB.a: CommonLib/CMakeFiles/COMMONLIB.dir/build.make
CommonLib/libCOMMONLIB.a: CommonLib/CMakeFiles/COMMONLIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libCOMMONLIB.a"
	cd /vagrant/workspace/CM_FW/build/CommonLib && $(CMAKE_COMMAND) -P CMakeFiles/COMMONLIB.dir/cmake_clean_target.cmake
	cd /vagrant/workspace/CM_FW/build/CommonLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COMMONLIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CommonLib/CMakeFiles/COMMONLIB.dir/build: CommonLib/libCOMMONLIB.a
.PHONY : CommonLib/CMakeFiles/COMMONLIB.dir/build

CommonLib/CMakeFiles/COMMONLIB.dir/requires: CommonLib/CMakeFiles/COMMONLIB.dir/src/Algrithm.c.o.requires
.PHONY : CommonLib/CMakeFiles/COMMONLIB.dir/requires

CommonLib/CMakeFiles/COMMONLIB.dir/clean:
	cd /vagrant/workspace/CM_FW/build/CommonLib && $(CMAKE_COMMAND) -P CMakeFiles/COMMONLIB.dir/cmake_clean.cmake
.PHONY : CommonLib/CMakeFiles/COMMONLIB.dir/clean

CommonLib/CMakeFiles/COMMONLIB.dir/depend:
	cd /vagrant/workspace/CM_FW/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/workspace/CM_FW /vagrant/workspace/CM_FW/CommonLib /vagrant/workspace/CM_FW/build /vagrant/workspace/CM_FW/build/CommonLib /vagrant/workspace/CM_FW/build/CommonLib/CMakeFiles/COMMONLIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CommonLib/CMakeFiles/COMMONLIB.dir/depend

