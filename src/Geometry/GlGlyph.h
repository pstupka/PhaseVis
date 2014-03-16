#ifndef GLYPH_H
#define	GLYPH_H

#include "Primitives.h"

/**
 * This class creates 3D arrows, which represent a vector in vector field.
 */
class GlGlyph{
    
    public:
        GlGlyph(double xPosition, double yPosition, double zPosition, double length, double theta, double phi);
        ~GlGlyph();

        void setPosition(double xPosition, double yPosition, double zPosition);
        void setLength (double length);
        void setTheta(double theta);
        void setPhi(double phi);
        void setFactor(double factor);
        void draw();

    private:
        // Geometry
        double xPosition_;
        double yPosition_;
        double zPosition_;

        double length_;
        double theta_;
        double phi_;

        double factor_;
};

#endif	/* GLYPH_H */

