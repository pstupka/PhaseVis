#include "Primitives.h"

#include <cmath>

void GlCylinder(GLdouble base, GLdouble top, GLdouble height,
        GLint slices , GLint stacks ,
        GLenum orientation ){
        
        GLUquadricObj *q ;     
        q = gluNewQuadric();
        gluQuadricOrientation (q , orientation ) ;
        gluCylinder(q, base, top, height, slices, stacks) ;
        gluDeleteQuadric (q) ;
}

void GlDisc(GLdouble inner, GLdouble outer, GLint slices, GLint loops,
        GLenum orientation){
    
        GLUquadricObj *q ;
        q = gluNewQuadric ( ) ;
        gluQuadricOrientation (q , orientation ) ;
        gluDisk (q , inner , outer , slices , loops );
        gluDeleteQuadric (q) ;
}

void GlCone(GLdouble base, GLdouble height,
        GLint slices , GLint stacks ,
        GLenum orientation   ){
    
        GLUquadricObj *q ;     
        q = gluNewQuadric();
        gluQuadricOrientation (q , orientation ) ;
        gluCylinder(q, base, 0, height, slices, stacks) ;
        gluDeleteQuadric (q) ;
}


GlVertex::GlVertex(){}


/**
 * Constructs OpenGL definition of vertex
 * @param x
 * @param y
 * @param z
 */
GlVertex::GlVertex(GLdouble x, GLdouble y, GLdouble z): x_(x), y_(y), z_(z) {}

/**
 *  Sets vertex coordinates.
 * @param x
 * @param y
 * @param z
 */
void GlVertex::setVertex(GLdouble x, GLdouble y, GLdouble z){
    x_ = x;
    y_ = y;
    z_ = z;
}

GlTriangle::GlTriangle(){
    v1_ = new GlVertex();
    v2_ = new GlVertex();
    v3_ = new GlVertex();
}


/**
 * Constructs OpenGL triangle 
 * @param v1 
 * @param v2
 * @param v3
 */
GlTriangle::GlTriangle(GlVertex* v1, GlVertex* v2, GlVertex* v3)
        : v1_(v1), v2_(v2), v3_(v3){
    calculateNormal();
}

GlTriangle::~GlTriangle(){
    delete v1_;
    delete v2_;
    delete v3_;
}

/**
 *  Sets vertexes of triangle.
 * @param v1
 * @param v2
 * @param v3
 */
void GlTriangle::setTriangle(GlVertex* v1, GlVertex* v2, GlVertex* v3){
    //if(vx_ != NULL) delete vx_; // prevents memory leak
    v1_ = v1;
    //if(vy_ != NULL) delete vy_;
    v2_ = v2;
    //if(vz_ != NULL) delete vz_;
    v3_ = v3;
    
    calculateNormal();
}

/**
 * This method calculates normal vectors of triangles surface.
 */
void GlTriangle::calculateNormal(){
        GlVertex a ;
        GlVertex b ;
        GLdouble len ;
        a.x_ = v1_ -> x_ - v2_ -> x_ ;
        a.y_ = v1_ -> y_ - v2_ -> y_ ;
        a.z_ = v1_ -> z_ - v2_ -> z_ ;


        b.x_ = v3_ ->x_ - v2_ ->x_ ;
        b.y_ = v3_ ->y_ - v2_ ->y_ ;
        b.z_ = v3_ ->z_ - v2_ ->z_ ;

        n_.x_ = a.y_ * b.z_ - a.z_ * b.y_;
        n_.y_ = a.z_ * b.x_ - a.x_ * b.z_;
        n_.z_ = a.x_ * b.y_ - a.y_ * b.x_;
        
        len = sqrt((n_.x_ * n_.x_)+(n_.y_ * n_.y_)+(n_.z_ * n_.z_));
        if (len){
            n_.x_ /= len;
            n_.y_ /= len;
            n_.z_ /= len;
        }
}

/**
 * Gets OpenGL definition of triangle.
 */
void GlTriangle::getGlDefinition(){
    glNormal3f(n_.x_, n_.y_, n_.z_);
    glVertex3f(v1_ -> x_, v1_ -> y_, v1_ -> z_  );
    glVertex3f(v2_ -> x_, v2_ -> y_, v2_ -> z_  );
    glVertex3f(v3_ -> x_, v3_ -> y_, v3_ -> z_  );
}