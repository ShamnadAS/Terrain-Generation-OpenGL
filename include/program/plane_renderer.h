#pragma once

#include "primitive_renderer.h"

class PlaneRenderer : public PrimitiveRenderer
{

public:
    virtual void initRenderData();
    virtual void DrawPrimitive(Vector3 position, float scale, Texture2D &texture);
    //constructor
    PlaneRenderer(Shader &shader);
    ~PlaneRenderer();

    unsigned int Rez;
};