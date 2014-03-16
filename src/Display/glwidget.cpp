/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
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
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
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
** $QT_END_LICENSE$
**
** Modified by Patryk Stupka. Original source code can be found at:
** http://qt-project.org/doc/qt-4.8/all-examples.html (Accessed at 15 Aug 2013)
** 
****************************************************************************/


#include <QtGui>
#include <QtOpenGL>

#include <cmath>
#include <iostream>

#include "glwidget.h"




#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif


GLWidget::GLWidget(QWidget *parent) 
        :QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
        xTranslate_(0), yTranslate_(0), xRot_(0), yRot_(0), zRot_(0),
        scale_(1), listID_(0), nList_(0){
    
    lightAmbient_[0] = 0.5f;
    lightAmbient_[1] = 0.5f;
    lightAmbient_[2] = 0.5f;
    lightAmbient_[3] = 1.0f;
    
    lightDiffuse_[0] = 1.0f;
    lightDiffuse_[1] = 1.0f;
    lightDiffuse_[2] = 1.0f;
    lightDiffuse_[3] = 1.0f;
    
    lightPosition_[0] = 0.0f;
    lightPosition_[1] = 0.0f;
    lightPosition_[2] = 2.0f;
    lightPosition_[3] = 1.0f;
}

GLWidget::~GLWidget(){
    
}

void GLWidget::saveImage()
{
    QImage image = grabFrameBuffer(true);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/stup",tr("Images (*.png *.xpm *.jpg *.tif *.bmp)"));   
    image.save(fileName);
}

void GLWidget::buildLists(QList<F*> f){
    if (listID_) glDeleteLists(listID_,nList_);
    nList_ = f.count();
    listID_ = glGenLists(nList_);
    for (uint i = listID_; i < listID_+nList_; i++){
        glNewList(i, GL_COMPILE); 
        f.at(i - listID_) -> draw();
        glEndList();  
    }
    functionsList_ = f;
    updateGL();
}

static void qNormalizeAngle(int &angle){
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::setXRotation(int angle){
    qNormalizeAngle(angle);
    if (angle != xRot_) {
        xRot_ = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setYRotation(int angle){
    qNormalizeAngle(angle);
    if (angle != yRot_) {
        yRot_ = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle){
    qNormalizeAngle(angle);
    if (angle != zRot_) {
        zRot_ = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setScale(double scale){
    if (scale_ != scale){
        scale_ = scale;
        emit scaleChanged(scale_);
        updateGL();
    }
}

void GLWidget::setXTranslate(double x){
    if (xTranslate_ != x){
        xTranslate_ = x;
        emit xTranslateChanged(x);
        updateGL();
    }
}

void GLWidget::setYTranslate(double y){
    if (yTranslate_ != y){
        yTranslate_ = y;
        emit yTranslateChanged(y);
        updateGL();
    }
}

void GLWidget::initializeGL(){
    glClearDepth(1.0f);             

    glEnable(GL_DEPTH_TEST);        //Test głębokości
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);        //Cieniowanie

    glEnable(GL_MULTISAMPLE);

    //glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse); 
    //glLightfv(GL_LIGHT0, GL_POSITION,lightPosition);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHTING);

    glEnable(GL_COLOR_MATERIAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

void GLWidget::paintGL(){
    glClearColor( 0.5, 0.5, 0.5 , 1.0 );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(scale_, scale_, scale_);
    glTranslatef(xTranslate_,yTranslate_,0.0f);
    
    glRotatef(xRot_ / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot_ / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot_ / 16.0, 0.0, 0.0, 1.0);
    
    if(listID_)
        for (uint i = listID_; i < listID_+nList_; i++)
                glCallList(i);
     
    /*glPushMatrix();
        //Układ współrzędnych
        glLineWidth(3.0);
        glBegin(GL_LINES);
            glColor3f(1.,0.,0.);    
            glVertex3f(0,0,0);      glVertex3f(0.1,0,0);
            glColor3f(0.,1.,0.);
            glVertex3f(0,0,0);      glVertex3f(0,0.1,0);
            glColor3f(0.,0.,1.);
            glVertex3f(0,0,0);      glVertex3f(0,0,0.1);
        glEnd();
    glPopMatrix();*/
}

void GLWidget::resizeGL(int width, int height){
    int side = qMax(width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 25.0);
    
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent *event){
    lastPos_ = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event){
	
    int dx = event->x() - lastPos_.x();
    int dy = event->y() - lastPos_.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot_ + 8 * dy);
        setYRotation(yRot_ + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot_ + 8 * dy);
        setZRotation(zRot_ + 8 * dx);
    } 
    else if (event -> buttons() & Qt::MiddleButton){
        //std::cerr<<"tup\n";
        setXTranslate(xTranslate_ + 0.002*dx/scale_);
        setYTranslate(yTranslate_ - 0.002*dy/scale_);
    }
    
    lastPos_ = event->pos();
}

void GLWidget::wheelEvent(QWheelEvent *event){
    event -> delta() > 0 ? setScale(scale_*1.1f) : setScale(scale_*0.9f);
    
}
