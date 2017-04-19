#ifndef MAPGLWIDGET_H
#define MAPGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class MapGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    MapGLWidget(QWidget *parent = 0);
    ~MapGLWidget();

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
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    int m_windowWidth;
    int m_windowHeight;
    float m_xMove;
    float m_yMove;
    int m_xRot;
    int m_yRot;
    int m_zRot;
    int m_zDistance;
    QPoint m_lastPos;
};
#endif
