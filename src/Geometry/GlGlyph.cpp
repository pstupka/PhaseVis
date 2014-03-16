#include "GlGlyph.h"

/**
 * Construct glyph.
 * @param xPosition X coordinate.
 * @param yPosition Y coordinate.
 * @param zPosition Z coordinate.
 * @param length Length of vector.
 * @param theta Theta angle in spheric coordinates.
 * @param phi Phi angle in spheric coordinates.
 */
GlGlyph::GlGlyph(double xPosition, double yPosition, double zPosition, double length, double theta, double phi) :
    xPosition_(xPosition), yPosition_(yPosition), zPosition_(zPosition), length_(length), theta_(theta), phi_(phi){
    factor_ = 1;
}

/**
 * Default destructor.
 */
GlGlyph::~GlGlyph(){
    
}

/**
 * Set (x,y,z) position of glyph.
 * @param xPosition 
 * @param yPosition
 * @param zPosition
 */
void GlGlyph::setPosition(double xPosition, double yPosition, double zPosition){
    xPosition_ = xPosition;
    yPosition_ = yPosition;
    zPosition_ = zPosition;
}

/**
 * Sets length of glyph.
 * @param length 
 */
void GlGlyph::setLength (double length){
    length_ = length;
}

/**
 * Sets theta angle of glyph.
 * @param theta
 */
void GlGlyph::setTheta(double theta){
    theta_ = theta;
}

/**
 * Sets phi angle of glyph.
 * @param phi
 */
void GlGlyph::setPhi(double phi){
    phi_ = phi;
}

/**
 * Sets length factor of glyph.
 * @param factor
 */
void GlGlyph::setFactor(double factor){
    factor_ = factor;
}

/**
 * Draws definition of object in OpenGL scene.
 */
void GlGlyph::draw(){
 
    glPushMatrix();
        glTranslated(xPosition_, yPosition_, zPosition_);
        glRotatef(90-theta_,0,1,0);
        glRotatef(-phi_,1,0,0);
        
    GlDisc(0,0.5*factor_,16,1, GLU_INSIDE);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(xPosition_, yPosition_, zPosition_);
         glRotatef(90-theta_,0,1,0);
         glRotatef(-phi_,1,0,0);
    GlCylinder(0.5*factor_,0.5*factor_,length_/2.,16,1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(xPosition_, yPosition_, zPosition_);
        glRotatef(90-theta_,0,1,0);
        glRotatef(-phi_,1,0,0);
    glTranslatef(0,0,length_/2.);
    GlDisc(0.5*factor_,1*factor_,16,1, GLU_INSIDE);
    glPopMatrix();   
    
    glPushMatrix();
    glTranslated(xPosition_, yPosition_, zPosition_);
        glRotatef(90-theta_,0,1,0);
        glRotatef(-phi_,1,0,0);
    glTranslatef(0,0,length_/2.);
    GlCylinder(1*factor_,0,length_/2.,16,1);
    glPopMatrix();
}