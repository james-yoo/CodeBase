#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_mapWidget = new MapGLWidget(this);
    m_mapWidget->setMinimumSize(640,480);

    //QVBoxLayout *mainLayout = new QVBoxLayout;
    //QHBoxLayout *container = new QHBoxLayout;
    //container->addWidget(glWidget);

    //QWidget *w = new QWidget;
    //w->setLayout(container);
    //mainLayout->addWidget(m_mapWidget);

    //setLayout(mainLayout);

    setCentralWidget(m_mapWidget);

    setWindowTitle(tr("Hello UrbanPilot"));
}

MainWindow::~MainWindow()
{
    delete m_mapWidget;
}
