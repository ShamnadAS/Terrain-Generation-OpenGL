#ifndef RENDER_PRIMITIVE
#define RENDER_PRIMITIVE

#include <glad/glad.h>
#include <math/Vectors.h>
#include <math/Matrices.h>

#include <utility/shader.h>
#include <utility/texture.h>

class PrimitiveRenderer
{
public:
    PrimitiveRenderer(Shader &shader);
    ~PrimitiveRenderer();
    virtual void DrawPrimitive(Vector3 position, float scale, Texture2D &texture);
protected:
    //Render state
    Shader shader;
    unsigned int VAO;
    //initialize and configure primitive's buffer and vertex attributes
    virtual void initRenderData();
};

#endif