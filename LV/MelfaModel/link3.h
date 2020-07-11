#ifndef LINK3_H
#define LINK3_H

#include <QString>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include "modelloader.h"

class Link3
{
public:
    Link3();
    void my_paintGL(int w_xRot, int y_Rot, int z_Rot, float w_scale, QMatrix4x4 w_projection, double degJ1, double degJ2);

private:
    void createShaderProgram( QString vShader, QString fShader);
    void createBuffers();
    void createAttributes();
    void setupLightingAndMatrices();

    void draw();
    void drawNode(const Node *node, QMatrix4x4 objectMatrix);
    void setMaterialUniforms(MaterialInfo &mater);

    QOpenGLShaderProgram m_shaderProgram;

    QOpenGLVertexArrayObject m_vao;

    QOpenGLBuffer m_vertexBuffer;
    QOpenGLBuffer m_normalBuffer;
    QOpenGLBuffer m_textureUVBuffer;
    QOpenGLBuffer m_indexBuffer;

    QSharedPointer<Node> m_rootNode;

    QMatrix4x4 m_projection, m_view, m_model, m_DH;

    QString m_filepath;
    ModelLoader::PathType m_pathType;
    QString m_texturePath;

    LightInfo m_lightInfo;
    MaterialInfo m_materialInfo;

    bool m_error;

    int m_xRot;
    int m_yRot;
    int m_zRot;

    float m_scale;
};

#endif // LINK3_H
