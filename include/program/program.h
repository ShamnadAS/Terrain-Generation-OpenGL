#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum ProgramState {
    PROGRAM_ACTIVE,
    PROGRAM_MENU
};

class Program
{
public: 
    // programme state
    bool                    Keys[1024];
    unsigned int            Width, Height;
    ProgramState State;

    // constructor/destructor
    Program(unsigned int width, unsigned int height);
    ~Program();
    // initialize programme state
    void Init();
    // programme loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

#endif