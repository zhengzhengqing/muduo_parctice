# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/main.cc.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/main.cc.o -c /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/main.cc

CMakeFiles/test.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/main.cc > CMakeFiles/test.dir/main.cc.i

CMakeFiles/test.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/main.cc -o CMakeFiles/test.dir/main.cc.s

CMakeFiles/test.dir/observer.cc.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/observer.cc.o: ../observer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/observer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/observer.cc.o -c /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/observer.cc

CMakeFiles/test.dir/observer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/observer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/observer.cc > CMakeFiles/test.dir/observer.cc.i

CMakeFiles/test.dir/observer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/observer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/observer.cc -o CMakeFiles/test.dir/observer.cc.s

CMakeFiles/test.dir/observable.cc.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/observable.cc.o: ../observable.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/observable.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/observable.cc.o -c /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/observable.cc

CMakeFiles/test.dir/observable.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/observable.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/observable.cc > CMakeFiles/test.dir/observable.cc.i

CMakeFiles/test.dir/observable.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/observable.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/observable.cc -o CMakeFiles/test.dir/observable.cc.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/main.cc.o" \
"CMakeFiles/test.dir/observer.cc.o" \
"CMakeFiles/test.dir/observable.cc.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/main.cc.o
test: CMakeFiles/test.dir/observer.cc.o
test: CMakeFiles/test.dir/observable.cc.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题 /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题 /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build /home/zzq/学习/study_for_good_life/Muduo_Test/shared_ptr解决多线程安全问题/build/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

