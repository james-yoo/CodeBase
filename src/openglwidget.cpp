#include <QMouseEvent>
//#include <QOpenGLShaderProgram>
#include <QCoreApplication>
#include <math.h>
#include "include/openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      m_xMove(0),m_yMove(0),m_xRot(0),m_yRot(0),m_zRot(0),m_zDistance(1.0)
{

}

OpenGLWidget::~OpenGLWidget()
{
    cleanup();
}

QSize OpenGLWidget::minimumSizeHint() const
{
    return QSize(640, 480);
}

QSize OpenGLWidget::sizeHint() const
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

void OpenGLWidget::setXTranslation(float t_x)
{
    if(t_x != m_xMove)
    {
        m_xMove = t_x;
        update();
    }
}


void OpenGLWidget::setYTranslation(float t_y)
{
    if(t_y != m_yMove)
    {
        m_yMove = t_y;
        update();
    }
}

void OpenGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
        //emit xRotationChanged(angle);
        update();
    }
}

void OpenGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
        //emit yRotationChanged(angle);
        update();
    }
}

void OpenGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
        //emit zRotationChanged(angle);
        update();
    }
}

void OpenGLWidget::setZoom(float t_z)
{
    if(t_z != m_zDistance)
    {
        m_zDistance -= t_z;
        if(m_zDistance < 0.1f)
            m_zDistance = 0.1f;
        if(m_zDistance > 10.0f)
            m_zDistance = 10.0f;

        update();
    }
}

void OpenGLWidget::cleanup()
{

}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.1, 0.1, 0.18, 0.0);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(m_xMove, m_yMove, -10.0);
    glRotatef(m_xRot/16, 1.0, 0.0, 0.0);
    glRotatef(m_yRot/16, 0.0, 1.0, 0.0);
    glRotatef(m_zRot/16, 0.0, 0.0, 1.0);
    glScalef(m_zDistance,m_zDistance, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0.5, 0);
    glEnd();
}

void OpenGLWidget::resizeGL(int width, int height)
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

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event)
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

void OpenGLWidget::wheelEvent(QWheelEvent *event)
{
    QPoint degree = event->angleDelta() / 8;

    if(!degree.isNull())
    {
        QPoint step = degree / 15;
        setZoom(step.y() * 0.1f);
        //m_zDistance -= step.y() * 0.5f;
    }
}

void OpenGLWidget::RenderText(double x, double y, double z, const QString &str, const QFont &font)
{
    int height = this->height();
    QPainter painter(this);
    GLdouble model[4][4], proj[4][4];
    GLdouble text_pos_x = 0.0, text_pos_y = 0.0, text_pos_z = 0.0;
    GLint view[4];

    glGetDoublev(GL_MODELVIEW_MATRIX, &model[0][0]);
    glGetDoublev(GL_PROJECTION_MATRIX, &proj[0][0]);
    glGetIntegerv(GL_VIEWPORT, &view[0]);

    Projection(x, y, z, &model[0][0], &proj[0][0], &view[0], &text_pos_x, &text_pos_y, &text_pos_z);

    text_pos_y = height - text_pos_y;

    painter.setPen(Qt::gray);
    painter.setFont(font);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.drawText(text_pos_x, text_pos_y, str);
    painter.end();
}

inline GLint OpenGLWidget::Projection(GLdouble objx, GLdouble objy, GLdouble objz, const GLdouble model[], const GLdouble proj[], const GLint viewport[], GLdouble *winx, GLdouble *winy, GLdouble *winz)
{
    GLdouble in[4], out[4];

    in[0] = objx; in[1] = objy; in[2] = objz; in[3] = 1.0;

    TransformPoint(out, model, in);
    TransformPoint(in, proj, out);

    if(in[3] == 0.0)
      return GL_FALSE;

    in[0] /= in[3];
    in[1] /= in[3];
    in[2] /= in[3];

    *winx = viewport[0] + (1 + in[0]) * viewport[2] / 2;
    *winy = viewport[1] + (1 + in[1]) * viewport[3] / 2;
    *winz = (1 + in[2]) / 2;

    return GL_TRUE;
}

inline void OpenGLWidget::TransformPoint(GLdouble out[], const GLdouble m[], const GLdouble in[])
{
#define M(row,col) m[col*4+row]

    out[0] = M(0,0) * in[0] + M(0,1) * in[1] + M(0,2) * in[2] + M(0,3) * in[3];
    out[1] = M(1,0) * in[0] + M(1,1) * in[1] + M(1,2) * in[2] + M(1,3) * in[3];
    out[2] = M(2,0) * in[0] + M(2,1) * in[1] + M(2,2) * in[2] + M(2,3) * in[3];
    out[3] = M(3,0) * in[0] + M(3,1) * in[1] + M(3,2) * in[2] + M(3,3) * in[3];
#undef M
}
