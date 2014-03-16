/* 
 * File:   Primitives.h
 * Author: stup
 *
 * Created on July 20, 2013, 10:07 PM
 */

#ifndef PRIMITIVES_H
#define	PRIMITIVES_H


#include <GL/glu.h>


/**
 * This is a helper function that creates cylinder.
 * @param base 
 * @param top 
 * @param height
 * @param slices
 * @param stacks
 * @param orientation 
 */
void    GlCylinder (GLdouble base, GLdouble top, GLdouble height,
        GLint slices, GLint stacks, GLenum orientation = GLU_OUTSIDE );


/**
 * Create OpenGL definition o disc.
 * @param inner
 * @param outer
 * @param slices
 * @param loops
 * @param orientation
 */
void    GlDisc(GLdouble inner, GLdouble outer, GLint slices, GLint loops,
        GLenum orientation = GLU_OUTSIDE );


/** Create OpenGL definition o cone. 
 * @param base
 * @param height
 * @param slices
 * @param stacks
 * @param orientation
 */
void    GlCone(GLdouble base, GLdouble height,
        GLint slices, GLint stacks,
        GLenum orientation = GLU_OUTSIDE);


/** OpenGL definition of simple vertex witt (x,y,z) coordinates.
 */
class GlVertex {
    public:
        GlVertex () ;
        GlVertex ( GLdouble x, GLdouble y, GLdouble z ) ;
        void setVertex ( GLdouble x, GLdouble y, GLdouble z ) ;

        GLdouble x_ ;
        GLdouble y_ ;
        GLdouble z_ ;
};


/**
 * OpenGL definition of triangle 
 */
class GlTriangle{
    public:
        GlTriangle();
        GlTriangle( GlVertex *v1 , GlVertex *v2, GlVertex *v3 ) ;
        ~GlTriangle();
        void setTriangle( GlVertex *v1, GlVertex *v2, GlVertex *v3 ) ;
        void calculateNormal();
        void getGlDefinition();

    private :
        GlVertex *v1_;
        GlVertex *v2_;
        GlVertex *v3_;
        GlVertex n_;
   
};


/** OpenGL primitive  
 */
class GlQuad{
    
};

#endif	/* PRIMITIVES_H */

