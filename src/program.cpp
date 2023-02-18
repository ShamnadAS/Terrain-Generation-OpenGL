#include <program/program.h>
#include <utility/resource_manager.h>
#include <program/plane_renderer.h>
#include <program/camera.h>

//program-related state variables
PlaneRenderer *Renderer;
Camera *camera;

//Constructor/destructor
Program::Program(unsigned int width, unsigned int height)
    : State(PROGRAM_ACTIVE), Keys(), Width(width), Height(height),IsMouseMoving(false)
{

}

Program::~Program()
{
    
}

void Program::Init()
{   
    ResourceManager::LoadTexture("texture/perlin_noise.png", true, "perlin");
    ResourceManager::LoadShader("shader/shader.vert", "shader/shader.frag", nullptr, nullptr, nullptr, "shader");
    Shader planeShader = ResourceManager::GetShader("shader");
    camera = new Camera();
    camera->Position = Vector3(0.0f, 0.25f, 0.5f);
    Renderer = new PlaneRenderer(planeShader);
    Renderer->initRenderData();
    WireFrame = true;
}

void Program::Update(float dt)
{
    Matrix4 projection = Matrix4().perspective(45.0f, (float)Width/(float)Height, 100.0f, 0.1f);
    ResourceManager::GetShader("shader").Use().SetMatrix4("projection", projection);
    Matrix4 view = camera->GetViewMatrix();
    ResourceManager::GetShader("shader").Use().SetMatrix4("view", view);
}

void Program::ProcessInput(float dt)
{
    if(Keys[GLFW_KEY_W])
    {
        camera->processKeyboard(FORWARD, dt);
    }
    if(Keys[GLFW_KEY_S])
    {
        camera->processKeyboard(BACKWARD, dt);
    }
    if(Keys[GLFW_KEY_A])
    {
        camera->processKeyboard(LEFT, dt);
    }
    if(Keys[GLFW_KEY_D])
    {
        camera->processKeyboard(RIGHT, dt);
    }
    if(IsMouseMoving)
    {
        camera->ProcessMouseMovement(MouseOffsetX, MouseOffsetY);
    }
}

void Program::Render()
{
    Texture2D perlinNoise = ResourceManager::GetTexture("perlin");
    Renderer->DrawPrimitive(Vector3(0, 0, 0), 1.0f, perlinNoise);
}
