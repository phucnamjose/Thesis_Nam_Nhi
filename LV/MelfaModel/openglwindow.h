#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>

#include <QString>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLFunctions>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include "modelloader.h"
#include "link1.h"
#include "link2.h"
#include "link3.h"
#include "link4.h"
#include "link5.h"
#include "link6.h"

class QScreen;
class QTimer;
class QOpenGLContext;

class OpenGLWindow : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenGLWindow( QWidget *parent = 0);
    ~OpenGLWindow();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    double degJ[5];

private:
    void mousePressEvent( QMouseEvent *event);
    void mouseMoveEvent( QMouseEvent *event );

    QPoint m_lastPos;

    void setXRotation( int angle );
    void setYRotation( int angle );
    void setZRotation( int angle );

    int m_xRot;
    int m_yRot;
    int m_zRot;

    void wheelEvent( QWheelEvent *event );

    void scalePlus();
    void scaleMinus();

    float m_scale;

    QOpenGLContext *createOpenGLContext(int major, int minor);

    QMatrix4x4 m_projection;

private:
    QOpenGLContext* m_context;
    QTimer *m_timer;
    Link1 *link1Handle = 0;
    Link2 *link2Handle = 0;
    Link3 *link3Handle = 0;
    Link4 *link4Handle = 0;
    Link5 *link5Handle = 0;
    //Link6 *link6Handle = 0;
};

#endif // OPENGLWINDOW_H
