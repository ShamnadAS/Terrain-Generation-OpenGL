#include <program/primitive_renderer.h>

PrimitiveRenderer::PrimitiveRenderer(Shader &shader)
{
    this->shader = shader;
    this->initRenderData();
}
PrimitiveRenderer::~PrimitiveRenderer()
{
    glDeleteVertexArrays(1, &this->VAO);
}
void PrimitiveRenderer::DrawPrimitive(Vector3 position, float scale, Texture2D &texture){}
void PrimitiveRenderer::initRenderData(){}