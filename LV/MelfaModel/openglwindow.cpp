#include "openglwindow.h"

#include <QCoreApplication>
#include <QKeyEvent>
#include <QOpenGLContext>
#include <QTimer>
#include <QDebug>

OpenGLWindow::OpenGLWindow(QWidget *parent) :
	QOpenGLWidget(parent)
    ,m_context(0)
    , m_timer(0)
    , m_xRot(0)
    , m_yRot(0)
    , m_zRot(0)
    , m_scale(1.0f)
    , degJ{-90, 90, 0,0, 0}
{
    m_context = createOpenGLContext(3, 3);

    setFormat( m_context->format() );
    resize( 800, 600 );
    create();

    //int refreshTime = 10;
    //m_timer = new QTimer;
    //m_timer->setInterval(refreshTime);
    //connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
    //m_timer->start();
}

OpenGLWindow::~OpenGLWindow()
{
}

void OpenGLWindow::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(.9f, .9f, .93f ,1.0f);
    link1Handle = new Link1();
    link2Handle = new Link2();
    link3Handle = new Link3();
    link4Handle = new Link4();
    link5Handle = new Link5();

    //link6Handle = new Link6();
}

QOpenGLContext * OpenGLWindow::createOpenGLContext(int major, int minor) {
    QSurfaceFormat requestedFormat;
    requestedFormat.setDepthBufferSize( 24 );
    requestedFormat.setMajorVersion( major );
    requestedFormat.setMinorVersion( minor );

    requestedFormat.setSamples( 4 );
    requestedFormat.setProfile( QSurfaceFormat::CoreProfile );

    QOpenGLContext *context = new QOpenGLContext;
    context->setFormat( requestedFormat );
    context->create();

    return context;
}

void OpenGLWindow::paintGL()
{
//    static int ii;
//    qDebug() << ii++;

   link1Handle->my_paintGL(m_xRot, m_yRot, m_zRot, m_scale, m_projection);
   link2Handle->my_paintGL(m_xRot, m_yRot, m_zRot, m_scale, m_projection, degJ[0]);
   link3Handle->my_paintGL(m_xRot, m_yRot, m_zRot, m_scale, m_projection, degJ[0], degJ[1]);
   link4Handle->my_paintGL(m_xRot, m_yRot, m_zRot, m_scale, m_projection, degJ[0], degJ[1], degJ[2]);
   link5Handle->my_paintGL(m_xRot, m_yRot, m_zRot, m_scale, m_projection, degJ[0], degJ[1], degJ[2], degJ[3]);
   //link6Handle->my_paintGL(m_xRot, m_yRot, m_zRot, m_scale, m_projection, degJ[0], degJ[1], degJ[2], degJ[3], degJ[4]);*/
}

void OpenGLWindow::resizeGL(int w, int h)
{
    glViewport( 0, 0, w, h );

    m_projection.setToIdentity();
    m_projection.perspective(45.0f, (float)w/h, 0.01f, 1000.0f);
}

void OpenGLWindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();

    if ( event->buttons() & Qt::LeftButton )
    {
        setXRotation( m_xRot + 8 * dy );
        setZRotation( m_zRot + 8 * dx );
    }
    else if ( event->buttons() & Qt::RightButton )
    {
        setXRotation( m_xRot + 8 * dy );
        setYRotation( m_yRot + 8 * dx );
    }

    m_lastPos = event->pos();
}

static void qNormalizeAngle( int &angle )
{
    while ( angle < 0 )
        angle += 360 * 16;

    while ( angle > 360 * 16 )
        angle -= 360 * 16;
}

void OpenGLWindow::setXRotation(int angle)
{
    qNormalizeAngle( angle );

    if ( angle != m_xRot )
    {
        m_xRot = angle;
    }
}

void OpenGLWindow::setYRotation(int angle)
{
    qNormalizeAngle( angle );

    if ( angle != m_yRot )
    {
        m_yRot = angle;
    }
}

void OpenGLWindow::setZRotation(int angle)
{
    qNormalizeAngle( angle );

    if ( angle != m_zRot )
    {
        m_zRot = angle;
    }
}

void OpenGLWindow::wheelEvent(QWheelEvent *event)
{
    if ( event->delta() > 0 )
        scalePlus();
    else if ( event->delta() < 0 )
        scaleMinus();
}

void OpenGLWindow::scalePlus()
{
    m_scale *= 1.1f;
}

void OpenGLWindow::scaleMinus()
{
    m_scale /= 1.1f;
}

void OpenGLWindow::setAngle(double deg0, double deg1, double deg2, double deg3)
{
	degJ[0] = deg0;
	degJ[1] = deg1;
	degJ[2] = deg2/1000;
	degJ[3] = deg3;
	update();
}