# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Git\Prog02\Ueb01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Git\Prog02\Ueb01\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Ueb01.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Ueb01.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Ueb01.dir\flags.make

CMakeFiles\Ueb01.dir\main.cpp.obj: CMakeFiles\Ueb01.dir\flags.make
CMakeFiles\Ueb01.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Git\Prog02\Ueb01\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ueb01.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Ueb01.dir\main.cpp.obj /FdCMakeFiles\Ueb01.dir\ /FS -c E:\Git\Prog02\Ueb01\main.cpp
<<

CMakeFiles\Ueb01.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ueb01.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\Ueb01.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Git\Prog02\Ueb01\main.cpp
<<

CMakeFiles\Ueb01.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ueb01.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Ueb01.dir\main.cpp.s /c E:\Git\Prog02\Ueb01\main.cpp
<<

# Object files for target Ueb01
Ueb01_OBJECTS = \
"CMakeFiles\Ueb01.dir\main.cpp.obj"

# External object files for target Ueb01
Ueb01_EXTERNAL_OBJECTS =

Ueb01.exe: CMakeFiles\Ueb01.dir\main.cpp.obj
Ueb01.exe: CMakeFiles\Ueb01.dir\build.make
Ueb01.exe: CMakeFiles\Ueb01.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Git\Prog02\Ueb01\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ueb01.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Ueb01.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Ueb01.dir\objects1.rsp @<<
 /out:Ueb01.exe /implib:Ueb01.lib /pdb:E:\Git\Prog02\Ueb01\cmake-build-debug\Ueb01.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Ueb01.dir\build: Ueb01.exe

.PHONY : CMakeFiles\Ueb01.dir\build

CMakeFiles\Ueb01.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ueb01.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Ueb01.dir\clean

CMakeFiles\Ueb01.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\Git\Prog02\Ueb01 E:\Git\Prog02\Ueb01 E:\Git\Prog02\Ueb01\cmake-build-debug E:\Git\Prog02\Ueb01\cmake-build-debug E:\Git\Prog02\Ueb01\cmake-build-debug\CMakeFiles\Ueb01.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Ueb01.dir\depend

