/* 
 * File:   Glyphs.h
 * Author: stup
 *
 * Created on July 16, 2013, 5:41 PM
 */

#ifndef GLYPHS_H
#define	GLYPHS_H

#include "F.h"
#include "GlGlyph.h"

class Glyphs : public F {
    
    public:
        Glyphs();
        virtual ~Glyphs();
        bool execute();
        bool updateOptions();
};

#endif	/* GLYPHS_H */

