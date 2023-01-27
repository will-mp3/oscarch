# Instructor's repository

This repository contains C++ projects created by the instructor for the class.

Projects:
1. [cmake_base_project](cmake_base_project): template of a C++ project that can be built using CMake through the command line or through the CLion IDE. It can be copied/pasted as a new project. If you do so, don't forget to change the project name in the scripts (*.sh and CMakeLists.txt).
2. [cpp_intro1](cpp_intro1): project that illustrates the basic features of C++ (variables, types, functions, pointers, etc.).
3. [cpp_oo_intro](cpp_oo_intro): project that illustrates the object-oriented features of C++ (classes, inheritance, polymorphism, etc.).
4. [memory_mgnt](memory_mgnt): small program used to illustrate how variables are created in the memory Stack and Heap.

# How can you run each project?

First of all, you need to clone this repository on your machine (by running `git clone [url_of_this_repository]` on the terminal) -- git should be installed on your machine. 
If you have cloned the repo and need to update your local copy of the repo, you can open the terminal, go to the directory of the repo, and run `git pull`.

A C++ project can be run through the command line (terminal) or through the CLion IDE, once g++, cmake, and CLion are installed on your machine.

## Running a project through the command line

Each project should contain two scripts:
* `build-run-unix.sh`: this one is for compiling/running the program on Linux or MacOS
* `build-run-win-msys2.sh`: this one is for compiling/running the program on Windows (through the "MSYS2 MinGW" terminal, not the Windows terminal)

On **Linux and MacOS**, open a terminal, go the directory of the project you want to run (e.g., `cd /home/[path_to_repo]/a0/cmake_base_project`), and run the script: `./build-run-unix.sh`. 
You may need to add execution permissions to the script by running `chmod +x ./build-run-unix.sh`

On **Windows**, open the **MSYS2 MinGW** terminal (not the Windows terminal), go the directory of the project you want to run (e.g., `cd /c/Users/[path_to_repo]/cmake_base_project`), and run the script: `./build-run-win-msys2.sh`. 

Once the script is executed, you should see the output of the program on the terminal.

*Note*: sometimes, when you experience weird compilation errors, you may need to compile from scratch. In that case, before running the scrips above, you need to delete the `build-unix` or `build-win-msys2` directories (e.g., `rm -r build-win-msys2`)

## Running a project through CLion

Configuration: once you install CLion on your Machine, it will guide you through configuring the MinGW C++ Toolchain within the IDE. It should work smoothly. However, for any problem, check [this page](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html#MinGW), which shows how to configure it step by step.

Follow the next steps after you have configured CLion correctly (*Note*: Mac users may see different menu options to those mentioned below).

Open CLion, click on `File --> Open...` (on the menu bar), select the directory of the project you want to run, and click `OK`.

Once the project is loaded (it may take a minute), click on `Build --> Build project` (on the menu bar), wait until it finishes compiling and creating the executable, and then click on `Run --> Run '[name_of_the_executable]'` (or just click the green triangle icon on the menu bar)

Once these steps are completed, you should see the output of the program on the "Run" panel of CLion.

*Note*: if there is any problem with building the project, you may want to retry reloading the project. You can do so by clicking `File --> Reload CMake project` (on the menu bar)
