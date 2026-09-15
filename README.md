Wanted to build myself a little template for building C++ raylib projects with
CMake for both web and desktop. This guide is for Linux only because that's what
I use. I'm not sure how to get this working on other operating systems.

# Requirements:
- CMake
- raylib
### If Building for Web:
- emscripten
- python (to serve the web build)
- A version of raylib compiled for web, which you can get by:
    1. Downloading the raylib source code from one of the releases
    2. Extract the source code and `cd` into the directory
    3. Edit the `CMakeLists.txt` to include the following lines:
        ```
        if (EMSCRIPTEN)
            set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
            set(CMAKE_EXECUTABLE_SUFFIX ".html") # This line is used to set your executable to build with the emscripten html template so that you can directly open it.
        endif ()
        ```
        You May also want to edit the line
        ```
        option(BUILD_EXAMPLES "Build the examples." ${PROJECT_IS_TOP_LEVEL})
        ```
        to instead be
        ```
        option(BUILD_EXAMPLES "Build the examples." OFF)
        ```
    4. Run `emcmake cmake -S . -B build`
    5. Run `cmake --build build`
    6. Make sure that the file `/build/raylib/libraylib.a` exits.

# Building/Running for Desktop:
In project root directory run:
- `cmake -B build` (only needs to be run once)
- `cmake --build build` (run to rebuild)
- `./build/project_name` (to run the program)

# Building/Running for Web:
Edit `CMakePresets.json` on line 7 to change `{PATH_TO_EMSCRIPTEN}` to the path
to emscripten on your local machine. For me this is `/usr/lib/emscripten/`.

Edit `CMakeLists.txt` on line 3 to change `project_name` to whatever you want to
name your project, and then again on line 22 to change `PATH_TO_RAYLIB` to the
path where you put the raylib source code on your local machine.

In project root directory run:
- `emcmake cmake -B web_build --preset Web` (only needs to be run once)
- `cmake --build web_build` (run to rebuild)
- `cd web_build` and `python -m http.server 8000` (to serve the web build on port 8000)
