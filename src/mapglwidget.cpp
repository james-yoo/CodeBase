#include <QMouseEvent>
//#include <QOpenGLShaderProgram>
#include <QCoreApplication>
#include <math.h>
#include "include/mapglwidget.h"

MapGLWidget::MapGLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      m_xMove(0),m_yMove(0),m_xRot(0),m_yRot(0),m_zRot(0),m_zDistance(0)
{

}

MapGLWidget::~MapGLWidget()
{
    cleanup();
}

QSize MapGLWidget::minimumSizeHint() const
{
    return QSize(640, 480);
}

QSize MapGLWidget::sizeHint() const
{
    return QSize(640, 480);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void MapGLWidget::setXTranslation(float t_x)
{
    if(t_x != m_xMove)
    {
        m_xMove = t_x;
        update();
    }
}


void MapGLWidget::setYTranslation(float t_y)
{
    if(t_y != m_yMove)
    {
        m_yMove = t_y;
        update();
    }
}

void MapGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
        //emit xRotationChanged(angle);
        update();
    }
}

void MapGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
        //emit yRotationChanged(angle);
        update();
    }
}

void MapGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
        //emit zRotationChanged(angle);
        update();
    }
}

void MapGLWidget::setZoom(float t_z)
{
    if(t_z != m_zDistance)
    {
        m_zDistance = t_z;
        update();
    }
}

void MapGLWidget::cleanup()
{

}

void MapGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.1, 0.1, 0.18, 0.0);
}

void MapGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(m_xMove, m_yMove, -10.0);
    glRotatef(m_xRot/16, 1.0, 0.0, 0.0);
    glRotatef(m_yRot/16, 0.0, 1.0, 0.0);
    glRotatef(m_zRot/16, 0.0, 0.0, 1.0);
    //glScalef();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0.5, 0);
    glEnd();
}

void MapGLWidget::resizeGL(int width, int height)
{
    m_windowWidth = width;
    m_windowHeight = height;
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, +1, -1, +1, 1.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void MapGLWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void MapGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();
    float dx_scale = dx * (1 / (float)m_windowWidth);
    float dy_scale = -dy * (1 / (float)m_windowHeight);

    if (event->buttons() & Qt::LeftButton)
    {
        setXTranslation(m_xMove + dx_scale);
        setYTranslation(m_yMove + dy_scale);
    } else if (event->buttons() & Qt::RightButton)
    {
        setXRotation(m_xRot + 8 * dy);
        setZRotation(m_zRot + 8 * dx);
    }
    m_lastPos = event->pos();
}

void MapGLWidget::wheelEvent(QWheelEvent *event)
{
    QPoint degree = event->angleDelta() / 8;

    if(degree.isNull())
    {
        QPoint step = degree / 15;
        m_zDistance -= step.y() * 0.5f;
    }
}
