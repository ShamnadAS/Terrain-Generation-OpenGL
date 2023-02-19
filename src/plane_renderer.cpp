#include <program/plane_renderer.h>
#include <utility/texture.h>

void PlaneRenderer::initRenderData()
{   
    // configure VAO/VBO
    unsigned int VBO;
    float vertices[] = { 
        // pos      // tex
       -0.5f, -0.5f, 0.0f, 0.0f, 
       -0.5f, 0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 1.0f, 1.0f,
    };

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void PlaneRenderer::DrawPrimitive(Vector3 position, float scale, Texture2D &texture)
{
    // prepare transformations
    this->shader.Use();
    Matrix4 model;
    //model.scale(scale);
    model.translate(position);
    this->shader.SetMatrix4("model", model);

    glActiveTexture(GL_TEXTURE0);   
    texture.Bind();

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_PATCHES, 0, 4);
    glBindVertexArray(0);
}

PlaneRenderer::PlaneRenderer(Shader &shader)
:PrimitiveRenderer(shader)
{
    
}
