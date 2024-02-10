**How to setup the project:**
1- Install  GCC C++ compiler (if not already installed). Follow the steps to install: https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites
2- Clone the project and open it on the vs code editor. 
3- Run the code (Don't worry if it shows error).
4- Replace the args on tasks.json with this:
``` 
               "-g",
                "-std=c++17",
                "-I${workspaceFolder}/include",
                "-L${workspaceFolder}/lib",
                "${workspaceFolder}/src/*.cpp",
                "${workspaceFolder}/src/glad.c",
                "-lglfw3dll",
                "-o",
                "${workspaceFolder}/myprogram.exe"
``` 
5- Now run the code again. It should work.
