#ifndef RENDER_PRIMITIVE
#define RENDER_PRIMITIVE

#include <glad/glad.h>
#include <math/Vectors.h>
#include <math/Matrices.h>

#include "shader.h"
#include "texture.h"

class PrimitiveRenderer
{
public:
    PrimitiveRenderer(Shader &shader);
    ~PrimitiveRenderer();
    virtual void DrawPrimitive(Vector3 position, Vector3 scale, Vector3 rotation);
private:
    //Render state
    Shader shader;
    unsigned int VAO;
    //initialize and configure primitive's buffer and vertex attributes
    virtual void initRenderData();
};

#endif