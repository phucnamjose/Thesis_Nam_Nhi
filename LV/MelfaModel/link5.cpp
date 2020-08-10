#include "Link5.h"
#include "openglwindow.h"
#include <QString>
#include <QtMath>

Link5::Link5() :// Class Link5 la con cua class OpenGLWindow (OpenGLWindow la class tu dinh nghia)
    m_indexBuffer(QOpenGLBuffer::IndexBuffer)
  , m_filepath("MelfaModel/models/Part5.STL")
  , m_pathType(ModelLoader::RelativePath)
  , m_error(false)
{
    createShaderProgram(":/shaders/shader.vert", ":/shaders/shader.frag");
    createBuffers();
    createAttributes();
    setupLightingAndMatrices();
}

void Link5::createShaderProgram(QString vShader, QString fShader)   // do^? bo'ng
{
    // Compile vertex shader    // dinh
    if ( !m_error && !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, vShader.toUtf8() ) ) {
        qDebug() << "Error in vertex shader:" << m_shaderProgram.log();
        m_error = true;
    }

    // Compile fragment shader  // manh
    if ( !m_error && !m_shaderProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, fShader.toUtf8() ) ) {
        qDebug() << "Error in fragment shader:" << m_shaderProgram.log();
        m_error = true;
    }

    // Link the shaders together into a program
    if ( !m_error && !m_shaderProgram.link() ) {
        qDebug() << "Error linking shader program:" << m_shaderProgram.log();
        m_error = true;
    }
}

void Link5::createBuffers()
{
    if(m_error)
        return;

    ModelLoader model;

    if(!model.Load(m_filepath, m_pathType))
    {
        m_error = true;
        return;
    }

    QVector<float> *vertices;
    QVector<float> *normals;
    QVector<QVector<float> > *textureUV;
    QVector<unsigned int> *indices;

    model.getBufferData(&vertices, &normals, &indices);
    model.getTextureData(&textureUV, 0, 0);

    // Create a vertex array object
    m_vao.create();
    m_vao.bind();

    // Create a buffer and copy the vertex data to it
    m_vertexBuffer.create();
    m_vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate( &(*vertices)[0], vertices->size() * sizeof( float ) );

    // Create a buffer and copy the vertex data to it
    m_normalBuffer.create();
    m_normalBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_normalBuffer.bind();
    m_normalBuffer.allocate( &(*normals)[0], normals->size() * sizeof( float ) );

    if(textureUV != 0 && textureUV->size() != 0)
    {
        // Create a buffer and copy the vertex data to it
        m_textureUVBuffer.create();
        m_textureUVBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_textureUVBuffer.bind();
        int texSize = 0;
        for(int ii=0; ii<textureUV->size(); ++ii)
            texSize += textureUV->at(ii).size();

        m_textureUVBuffer.allocate( &(*textureUV)[0][0], texSize * sizeof( float ) );
    }

    // Create a buffer and copy the index data to it
    m_indexBuffer.create();
    m_indexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
    m_indexBuffer.bind();
    m_indexBuffer.allocate( &(*indices)[0], indices->size() * sizeof( unsigned int ) );

    m_rootNode = model.getNodeData();
}

void Link5::createAttributes()
{
    if(m_error)
        return;

    m_vao.bind();
    // Set up the vertex array state
    m_shaderProgram.bind();

    // Map vertex data to the vertex shader's layout location '0'
    m_vertexBuffer.bind();
    m_shaderProgram.enableAttributeArray( 0 );      // layout location
    m_shaderProgram.setAttributeBuffer( 0,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        3);         // number of components (3 for x,y,z)

    // Map normal data to the vertex shader's layout location '1'
    m_normalBuffer.bind();
    m_shaderProgram.enableAttributeArray( 1 );      // layout location
    m_shaderProgram.setAttributeBuffer( 1,          // layout location
                                        GL_FLOAT,   // data's type
                                        0,          // Offset to data in buffer
                                        3);         // number of components (3 for x,y,z)

    if(m_textureUVBuffer.isCreated()) {
        m_textureUVBuffer.bind();
        m_shaderProgram.enableAttributeArray( 2 );      // layout location
        m_shaderProgram.setAttributeBuffer( 2,          // layout location
                                            GL_FLOAT,   // data's type
                                            0,          // Offset to data in buffer
                                            2);         // number of components (2 for u,v)
    }
}

void Link5::setupLightingAndMatrices()
{
    m_view.setToIdentity();
    m_view.lookAt(
                QVector3D(0.0f, 0.0f, 1.2f),    // Camera Position
                QVector3D(0.0f, 0.0f, 0.0f),    // Point camera looks towards
                QVector3D(0.0f, 1.0f, 0.0f));   // Up vector

    m_lightInfo.Position = QVector4D( -1.0f, 1.0f, 1.0f, 1.0f );
    m_lightInfo.Intensity = QVector3D( 1.0f, 1.0f, 1.0f);

 	m_materialInfo.Ambient = QVector3D(0.05f, 0.05f, 0.2f);   // mau xung quanh
    m_materialInfo.Diffuse = QVector3D( 0.3f, 0.5f, 0.3f );   // mau khuech tan
    m_materialInfo.Specular = QVector3D( 0.6f, 0.6f, 0.6f );  // mau phan chieu
    m_materialInfo.Shininess = 50.0f;
}

void Link5::my_paintGL(int w_xRot, int w_yRot, int w_zRot, float w_scale, QMatrix4x4 w_projection, double degJ1, double degJ2, double degJ3, double degJ4)
{
    if(m_error)
        return;

    m_xRot = w_xRot;
    m_yRot = w_yRot;
    m_zRot = w_zRot;
    m_scale = w_scale;
    m_projection = w_projection;

    // Bind shader program
    m_shaderProgram.bind(); // set as current shader program

    // Set the model matrix
    // Translate and rotate it a bit to get a better view of the model
    m_model.setToIdentity();
    m_model.translate(0,-0.4f,0);
    m_model.rotate(-90+float(m_xRot)/16.0f, 1.0f, 0.0f, 0.0f); // thay doi he toa do Base, cho Oz huong len
    m_model.rotate(float(m_yRot)/16.0f, 0.0f, 1.0f, 0.0f);      // m_xRot, m_yRot, m_zRot, m_scale duoc thua huong vo dieu kien tu class OpenGLWindow
    m_model.rotate(float(m_zRot)/16.0f, 0.0f, 0.0f, 1.0f);
    m_model.scale(m_scale);

    // Set shader uniforms for light information
    m_shaderProgram.setUniformValue( "lightPosition", m_lightInfo.Position );
    m_shaderProgram.setUniformValue( "lightIntensity", m_lightInfo.Intensity );

    // Calculate DH matrix
    //double d1 = 0.3f, a2 = 0.25f, a3 = 0.16f;
    double L2 = 0.16f,L1 = 0.197f,alpha = 0.0f,d1 = 0.211,d4=0.083;
    degJ1 = qDegreesToRadians(degJ1);
    degJ2 = qDegreesToRadians(degJ2);
    //degJ3 = qDegreesToRadians(degJ3);
    degJ4 = qDegreesToRadians(degJ4);
    double c1 = cos(degJ1), s1 = sin(degJ1);
    double c2 = cos(degJ2), s2 = sin(degJ2);
	double c4 = cos(degJ4);
	double s4 = sin(degJ4);
	double c12 = cos(degJ1 + degJ2);
	double s12 = sin(degJ1 + degJ2);
   /* m_DH = QMatrix4x4( c1*c234, -s1, c1*s234, c1*(a2*s2 + a3*s23),
                       c234*s1,  c1, s1*s234, s1*(a2*s2 + a3*s23),
                         -s234,   0,    c234, d1 + a2*c2 + a3*c23,
                             0,   0,       0,                   1);*/
    m_DH = QMatrix4x4 ( c12*c4 + s12*s4, -c12*s4 + s12*c4, 0, L1*c1 + L2*c12,
                        s12*c4 - c12*s4, -s12*s4 - c12*c4, 0, L1*s1 + L2*s12,
                        0,                              0,-1, d1- degJ3 - d4,
                        0,                              0, 0, 1);

    // Bind VAO and draw everything with drawNode()
    m_vao.bind();
    drawNode(m_rootNode.data(), m_DH);
    m_vao.release();
}

void Link5::drawNode(const Node *node, QMatrix4x4 objectMatrix)
{
    // Prepare matrices
    objectMatrix *= node->transformation;
    QMatrix4x4 modelMatrix = m_model * objectMatrix;
    QMatrix4x4 modelViewMatrix = m_view * modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_projection * modelViewMatrix;

    m_shaderProgram.setUniformValue( "MV", modelViewMatrix );// Transforming to eye space
    m_shaderProgram.setUniformValue( "N", normalMatrix );    // Transform normal to Eye space
    m_shaderProgram.setUniformValue( "MVP", mvp );           // Matrix for transforming to Clip space

    // Draw each mesh in this node
    for(int imm = 0; imm<node->meshes.size(); ++imm)
    {
        if(node->meshes[imm]->material->Name == QString("DefaultMaterial"))
            setMaterialUniforms(m_materialInfo);    // Default Mesh from code
        else
            setMaterialUniforms(*node->meshes[imm]->material);  // Custom Mesh from model file

        glDrawElements( GL_TRIANGLES, node->meshes[imm]->indexCount, GL_UNSIGNED_INT
                            , (const void*)(node->meshes[imm]->indexOffset * sizeof(unsigned int)) );
    }

    // Recursively draw this nodes children nodes
    for(int inn = 0; inn<node->nodes.size(); ++inn)
        drawNode(&node->nodes[inn], objectMatrix);
}

void Link5::setMaterialUniforms(MaterialInfo &mater)
{
    m_shaderProgram.setUniformValue( "Ka", mater.Ambient );
    m_shaderProgram.setUniformValue( "Kd", mater.Diffuse );
    m_shaderProgram.setUniformValue( "Ks", mater.Specular );
    m_shaderProgram.setUniformValue( "shininess", mater.Shininess );
}
