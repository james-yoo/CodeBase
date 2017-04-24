/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //QVBoxLayout *mainLayout = new QVBoxLayout;
    //mainLayout->setMenuBar(m_menuBar);
    m_mapWidget = new MapGLWidget(this);
    m_mapWidget->setMinimumSize(640,480);
    setCentralWidget(m_mapWidget);

    createActions();
    //QGridLayout *grid = new QGridLayout;
    //grid->addWidget(m_mapWidget, 0, 0);
    //grid->addWidget(createShapeLoadGroupBox(), 0, 0);
    //setLayout(grid);
    //QVBoxLayout *mainLayout = new QVBoxLayout;
    //QHBoxLayout *container = new QHBoxLayout;
    //container->addWidget(glWidget);

    //QWidget *w = new QWidget;
    //w->setLayout(container);
    //mainLayout->addWidget(m_mapWidget);

    //setLayout(mainLayout);



    setWindowTitle(tr("Hello CodeBase"));
}

MainWindow::~MainWindow()
{
    delete m_mapWidget;
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newLetterAct = new QAction(newIcon, tr("&New Letter"), this);
    newLetterAct->setShortcuts(QKeySequence::New);
    newLetterAct->setStatusTip(tr("Create a new form letter"));
    //connect(newLetterAct, &QAction::triggered, this, &MainWindow::newLetter);
    fileMenu->addAction(newLetterAct);
    //fileToolBar->addAction(newLetterAct);

    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    QAction *saveAct = new QAction(saveIcon, tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the current form letter"));
    //connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(saveAct);
    //fileToolBar->addAction(saveAct);

    const QIcon printIcon = QIcon::fromTheme("document-print", QIcon(":/images/print.png"));
    QAction *printAct = new QAction(printIcon, tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the current form letter"));
    //connect(printAct, &QAction::triggered, this, &MainWindow::print);
    fileMenu->addAction(printAct);
    //fileToolBar->addAction(printAct);

    fileMenu->addSeparator();

    QAction *quitAct = fileMenu->addAction(tr("&Quit"), this, &QWidget::close);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Quit the application"));


    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));

    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
}

void MainWindow::createControlGroupBox()
{

}

void MainWindow::about()
{
 QMessageBox::about(this, QString("About Hello CodeBase"),
          QString("The <b>CodeBase</b> example demonstrates how to "
             "create Qt based application. "));
}
