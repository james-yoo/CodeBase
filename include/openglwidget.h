#ifndef MAPGLWIDGET_H
#define MAPGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPainter>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenGLWidget(QWidget *parent = 0);
    ~OpenGLWidget();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setXTranslation(float t_x);
    void setYTranslation(float t_y);
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setZoom(float t_z);
    void cleanup();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    int m_windowWidth;
    int m_windowHeight;
    float m_xMove;
    float m_yMove;
    int m_xRot;
    int m_yRot;
    int m_zRot;
    float m_zDistance;
    QPoint m_lastPos;

    void RenderText(double x, double y, double z, const QString &str, const QFont &font = QFont("Helvetica",9));
    inline GLint Projection(GLdouble objx, GLdouble objy, GLdouble objz, const GLdouble model[16], const GLdouble proj[16], const GLint viewport[4], GLdouble *winx, GLdouble *winy, GLdouble *winz);
    inline void TransformPoint(GLdouble out[4], const GLdouble m[16], const GLdouble in[4]);
};
#endif
