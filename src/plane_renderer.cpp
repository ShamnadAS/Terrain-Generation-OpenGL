#include <program/plane_renderer.h>
#include <utility/texture.h>
#include <vector>

void PlaneRenderer::initRenderData()
{   
    unsigned int width, height;
    Rez = 5;
    width = 1;
    height = 1;
    // configure VAO/VBO
    unsigned int VBO;
    std::vector<float> vertices;
    for (int i = 0; i <= Rez - 1; i++)
    {
        for (int  j = 0; j <= Rez - 1; j++)
        {    
            //Debug the values  
            vertices.push_back(-(float)width/2.0f + (float)width*i/(float)Rez); //x
            vertices.push_back(-(float)height/2.0f + (float)height*j/(float)Rez); //y
            vertices.push_back(i/(float)Rez); //u
            vertices.push_back(j/(float)Rez); //v

            vertices.push_back(-(float)width/2.0f + (float)width*(i+1)/(float)Rez); //x
            vertices.push_back(-(float)height/2.0f + (float)height*j/(float)Rez); //y
            vertices.push_back((i+1)/(float)Rez); //u
            vertices.push_back(j/(float)Rez); //v

            vertices.push_back(-(float)width/2.0f + (float)width*i/(float)Rez); //x
            vertices.push_back(-(float)height/2.0f + (float)height*(j+1)/(float)Rez); //y
            vertices.push_back(i/(float)Rez); //u
            vertices.push_back((j+1)/(float)Rez); //v

            vertices.push_back(-(float)width/2.0f + (float)width*(i+1)/(float)Rez); //x
            vertices.push_back(-(float)height/2.0f + (float)height*(j+1)/(float)Rez); //y
            vertices.push_back((i+1)/(float)Rez); //u
            vertices.push_back((j+1)/(float)Rez); //v
        }
    }
    
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

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
    glDrawArrays(GL_PATCHES, 0, 4 * Rez * Rez);
    glBindVertexArray(0);
}

PlaneRenderer::PlaneRenderer(Shader &shader)
:PrimitiveRenderer(shader)
{
    
}
