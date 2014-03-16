
#ifndef COLORMAPPER_H
#define	COLORMAPPER_H

#include "F.h"

/**
 * ColorMapper is a visualization method to create scalar visualization of vector field. 
 * It is based on color mapping method. The only thing this method do is color grid according to 
 * magnitude of vectors.
 * @todo Add color table to map colors.
 */

class ColorMapper : public F{
    public: 
        ColorMapper();
        ~ColorMapper();
        
        bool execute();
        bool updateOptions();
        
        int factor1_;
        int factor2_;
        int factor3_;
};

#endif	/* COLORMAPPER_H */

