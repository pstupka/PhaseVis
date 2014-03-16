#ifndef DYETRACKING_H
#define	DYETRACKING_H

#include "F.h"


void hsv2rgb(float h, float s, float v, float& r, float& g, float& b);

/**
 * Dye tracking method computes streamplite of every cell in vector field and increases table 
 * of intensity of colour. 
 */
class DyeTracking : public F{

public:
	DyeTracking();
	~DyeTracking();
	bool execute();
        bool updateOptions();
        void draw();
        
private:
        //Streamline
        double dt_;  
        double maxTime_;
        
        //Leak
        double cLimit_;
        
        //Color coding
        double colorHue_;
        double colorBrightness_;
        
        std::vector <double> C_;  
};


#endif	/* DYETRACKING_H */

