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
    createMenu();
    createControlGroupBox();

    //QVBoxLayout *mainLayout = new QVBoxLayout;
    //mainLayout->setMenuBar(m_menuBar);
    m_mapWidget = new MapGLWidget(this);
    m_mapWidget->setMinimumSize(640,480);
    setCentralWidget(m_mapWidget);

    //QTextEdit *bigEditor = new QTextEdit;
    //bigEditor->setPlainText(tr("This widget takes up all the remaining space "
       //                        "in the top-level layout."));

    //QGridLayout *grid = new QGridLayout;

    //grid->addWidget(m_mapWidget, 0, 0);
    //grid->addWidget(bigEditor, 0, 0);
    //grid->addWidget(m_horizontalGroupBox, 0, 1);
    //setLayout(grid);


    setWindowTitle(tr("Hello CodeBase project"));
}

MainWindow::~MainWindow()
{
    delete m_mapWidget;
}

void MainWindow::createMenu()
{
    //m_menuBar = new QMenuBar;

    //m_fileMenu = new QMenu(tr("&File"), this);
    //m_exitAction = m_fileMenu->addAction(tr("E&xit"));
    //m_menuBar->addMenu(m_fileMenu);

    //connect(m_exitAction, SIGNAL(triggered()), this, SLOT(accept()));

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *fileOpenAct = new QAction(QString("&Open File"), this);
    fileOpenAct->setShortcuts(QKeySequence::New);
    fileOpenAct->setStatusTip(QString("Open shape format file"));
    //connect(newLetterAct, &QAction::triggered, this, &MainWindow::newLetter);
    fileMenu->addAction(fileOpenAct);

    fileMenu->addSeparator();

    QAction *quitAct = fileMenu->addAction(tr("&Quit"), this, &QWidget::close);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Quit the application"));

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *aboutAct = helpMenu->addAction(QString("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));

    QAction *aboutQtAct = helpMenu->addAction(QString("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));

}

void MainWindow::createControlGroupBox()
{
    m_horizontalGroupBox = new QGroupBox(QString("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < 4; ++i) {
        buttons[i] = new QPushButton(QString("Button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    m_horizontalGroupBox->setLayout(layout);
}

void MainWindow::about()
{
 QMessageBox::about(this, QString("About Hello CodeBase"),
          QString("The <b>CodeBase</b> example."));
}
